#include <Gwent/Plugins/ImagePlugin.hpp>
#include <Gwent/Plugins/MenuUIPlugin.hpp>
#include <Gwent/Plugins/WindowResizePlugin.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/Core/Filepath.hpp>
#include <R-Engine/ECS/Query.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>

#include <Gwent/Card/Cards.hpp>

#include <Gwent/UI/DeckBuilder.hpp>
#include <Gwent/UI/Style.hpp>
#include <Gwent/UI/Text.hpp>

#include <cmath>

namespace {

/**
 * private
 */
// clang-format off

static constexpr f32 g_card_width_relative = 0.10f;
static constexpr f32 g_card_aspect_ratio = 775.f / 410.f;
static constexpr u8 g_cards_per_row = 3;
static constexpr f32 g_padding_relative = 0.01f;
static constexpr r::Vec2f g_initial_offset_relative = {0.05f, 0.05f};

static inline const std::string get_card_path(const std::string &faction, const std::string_view &filename) noexcept
{
    return r::path::get("assets/cards/" + faction + "_" + std::string(filename) + ".jpg");
}

static const struct {
        const std::string content;
        const r::gwent::StatType type;
        const r::Color color;
        const f32 font_size = 24.f;
} g_text_elements[] = {
    {
        .content = "Total cards in deck",
        .type = r::gwent::StatType::TotalCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0",
        .type = r::gwent::StatType::TotalCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    },
    {
        .content = "Number of Unit Cards",
        .type = r::gwent::StatType::UnitCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0",
        .type = r::gwent::StatType::UnitCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    },
    {
        .content = "Special Cards",
        .type = r::gwent::StatType::SpecialCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0",
        .type = r::gwent::StatType::SpecialCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    },
    {
        .content = "Hero Cards",
        .type = r::gwent::StatType::HeroCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0", 
        .type = r::gwent::StatType::HeroCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    }
};

/**
 * systems
 */

/**
 * startup
 */

static void startup_spawn_all_cards(r::ecs::Commands &commands)
{
    for (const auto &card_data : r::gwent::g_realms_cards) {

        if (card_data->row == r::gwent::Row::Leader) {
            continue;
        }
        
        commands.spawn(
            r::gwent::Image{
                .path = get_card_path("realms", card_data->filename)
            },
            r::gwent::Style{
                .position = {0, 0}, .size = {1, 1}
            },
            r::gwent::GwentCard{
                .id = card_data->id
            },
            r::gwent::CardPanel{
                .current_panel = r::gwent::CardPanel::Panel::AVAILABLE
            }
        );
    }
}

static void startup_spawn_all_text(r::ecs::Commands &commands) {
    float y_offset = -100.f;

    for (const auto &text_data : g_text_elements) {
        commands.spawn(
            r::gwent::Text{ .content = text_data.content },
            r::gwent::Style{ .color = text_data.color, .font_size = text_data.font_size },
            r::gwent::StatText{ .type = text_data.type },
            r::gwent::TextLayout{
                .pivot = { 0.5f, 0.0f },
                .relative_position = { 0.5f, 0.5f },
                .offset = { 0.f, y_offset }
            }
        );
        y_offset += text_data.font_size + 10.f;
    }
}

/**
 * update
 */

static void update_scrolling_input(
    r::ecs::Res<r::UserInput> input,
    r::ecs::Res<r::gwent::WindowSize> window_size,
    r::ecs::ResMut<r::gwent::DeckBuilderState> scroll_state
) noexcept {
    const f32 scroll_delta = input.ptr->mouse_wheel;

    if (r::F32::equal(scroll_delta, 0.f)) {
        return;
    }

    const f32 scroll_amount = 50.f * scroll_delta;

    if (input.ptr->mouse_position.x < window_size.ptr->current.x / 2.0f) {
        scroll_state.ptr->available_panel.target_offset -= scroll_amount;
    } else {
        scroll_state.ptr->selected_panel.target_offset -= scroll_amount;
    }

    scroll_state.ptr->available_panel.target_offset = std::max(0.f, scroll_state.ptr->available_panel.target_offset);
    scroll_state.ptr->selected_panel.target_offset = std::max(0.f, scroll_state.ptr->selected_panel.target_offset);
}

static void update_deck_builder_stats(
    r::ecs::Query<r::ecs::Ref<r::gwent::GwentCard>, r::ecs::Ref<r::gwent::CardPanel>> card_query,
    r::ecs::Query<r::ecs::Mut<r::gwent::Text>, r::ecs::Ref<r::gwent::StatText>> text_query
) {
    struct DeckStats { u32 total=0, units=0, specials=0, heroes=0; } stats;

    for (const auto &[gwent_card, panel] : card_query) {
        if (panel.ptr->current_panel == r::gwent::CardPanel::Panel::SELECTED) {
            ++stats.total;
            const auto card_db_entry = r::gwent::find_card(gwent_card.ptr->id);
            if (card_db_entry.deck == r::gwent::DeckFaction::Special) ++stats.specials; else ++stats.units;
            if (card_db_entry.ability.find("hero") != std::string_view::npos) ++stats.heroes;
        }
    }
    for (const auto &[text, stat_marker] : text_query) {
        switch (stat_marker.ptr->type) {
            case r::gwent::StatType::TotalCountValue:   text.ptr->content = std::to_string(stats.total); break;
            case r::gwent::StatType::UnitCountValue:    text.ptr->content = std::to_string(stats.units); break;
            case r::gwent::StatType::SpecialCountValue: text.ptr->content = std::to_string(stats.specials); break;
            case r::gwent::StatType::HeroCountValue:    text.ptr->content = std::to_string(stats.heroes); break;
            default: break;
        }
    }
}

static void update_smooth_scrolling(
    r::ecs::ResMut<r::gwent::DeckBuilderState> scroll_state,
    r::ecs::Res<r::core::FrameTime> time
) noexcept
{
    auto &available = scroll_state.ptr->available_panel;
    auto &selected = scroll_state.ptr->selected_panel;
    const f32 dt = time.ptr->delta_time;

    available.current_offset = std::lerp(available.current_offset, available.target_offset, dt * available.scroll_speed);
    selected.current_offset = std::lerp(selected.current_offset, selected.target_offset, dt * selected.scroll_speed);
}

static void update_card_clicking(
    r::ecs::Res<r::UserInput> input,
    r::ecs::Query<r::ecs::Ref<r::gwent::Style>, r::ecs::Mut<r::gwent::CardPanel>> query
) noexcept
{
    if (!input.ptr->isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return;
    }

    for (auto [style, panel] : query) {
        const auto &pos = style.ptr->position;
        const auto &size = style.ptr->size;
        const auto &mouse_pos = input.ptr->mouse_position;

        if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.width && 
            mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.height) {
            
            if (panel.ptr->current_panel == r::gwent::CardPanel::Panel::AVAILABLE) {
                panel.ptr->current_panel = r::gwent::CardPanel::Panel::SELECTED;
            } else {
                panel.ptr->current_panel = r::gwent::CardPanel::Panel::AVAILABLE;
            }
            
            break;
        }
    }
}

static void update_card_positions(
    r::ecs::Query<r::ecs::Ref<r::gwent::CardPanel>, r::ecs::Mut<r::gwent::Style>> query,
    r::ecs::Res<r::gwent::WindowSize> window_size,
    r::ecs::Res<r::gwent::DeckBuilderState> scroll_state
) noexcept
{
    const f32 window_width = window_size.ptr->current.x;
    const f32 card_width = window_width * g_card_width_relative;
    const f32 card_height = card_width * g_card_aspect_ratio;
    const f32 padding = window_width * g_padding_relative;
    const f32 content_width_per_panel = (g_cards_per_row * card_width) + ((g_cards_per_row > 1 ? g_cards_per_row - 1 : 0) * padding);

    u32 available_idx = 0;
    u32 selected_idx = 0;

    for (auto [panel, style] : query) {
        u32 index_in_panel;
        r::Vec2f initial_offset;
        f32 scroll_offset;

        if (panel.ptr->current_panel == r::gwent::CardPanel::Panel::AVAILABLE) {
            index_in_panel = available_idx++;
            initial_offset = {padding, padding}; 
            scroll_offset = scroll_state.ptr->available_panel.current_offset;
        } else { // Panel::SELECTED
            index_in_panel = selected_idx++;
            
            const f32 right_panel_start_x = window_width - content_width_per_panel - padding;
            
            initial_offset = {right_panel_start_x, padding};
            scroll_offset = scroll_state.ptr->selected_panel.current_offset;
        }

        const u8 row = index_in_panel / g_cards_per_row;
        const u8 col = index_in_panel % g_cards_per_row;

        style.ptr->position = {
            initial_offset.x + col * (card_width + padding),
            initial_offset.y + row * (card_height + padding) - scroll_offset
        };
        style.ptr->size = {
            card_width,
            card_height
        };
    }
}

}// namespace

/**
* public
*/

void r::gwent::MenuUIPlugin::build(r::Application &app)
{
    app.insert_resource(r::gwent::DeckBuilderState{})
       .add_systems<startup_spawn_all_cards, startup_spawn_all_text>(r::Schedule::STARTUP)
       .add_systems<
            update_scrolling_input,
            update_smooth_scrolling,
            update_card_clicking,
            update_card_positions,
            update_deck_builder_stats
        >(r::Schedule::UPDATE);
}
