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

/**
 * systems
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

static void handle_scrolling_input(
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

static void handle_card_clicking(
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
    const f32 window_height = window_size.ptr->current.y;
    const f32 card_width = window_width * g_card_width_relative;
    const f32 card_height = card_width * g_card_aspect_ratio;
    const f32 padding = window_width * g_padding_relative;
    const f32 half_screen = window_width / 2.f;

    u32 available_idx = 0;
    u32 selected_idx = 0;

    for (auto [panel, style] : query) {
        u32 index_in_panel;
        r::Vec2f initial_offset;
        f32 scroll_offset;

        if (panel.ptr->current_panel == r::gwent::CardPanel::Panel::AVAILABLE) {
            index_in_panel = available_idx;
            ++available_idx;
            initial_offset = {padding, padding};
            scroll_offset = scroll_state.ptr->available_panel.current_offset;
        } else {
            index_in_panel = selected_idx;
            ++selected_idx;
            initial_offset = {half_screen + padding, padding};
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
        .add_systems<startup_spawn_all_cards>(r::Schedule::STARTUP)
        .add_systems<handle_scrolling_input>(r::Schedule::UPDATE)
        .add_systems<update_smooth_scrolling>(r::Schedule::UPDATE)
        .add_systems<handle_card_clicking>(r::Schedule::UPDATE)
        .add_systems<update_card_positions>(r::Schedule::UPDATE);
}
