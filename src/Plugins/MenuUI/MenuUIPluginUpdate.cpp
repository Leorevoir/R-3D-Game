#include <Gwent/Plugins/MenuUIPlugin.hpp>
#include <Gwent/Plugins/WindowResizePlugin.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/Core/Backend.hpp>
#include <R-Engine/Core/Logger.hpp>
#include <R-Engine/ECS/Query.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>

#include <Gwent/Card/Cards.hpp>
#include <Gwent/States.hpp>

#include <Gwent/UI/DeckBuilder.hpp>
#include <Gwent/UI/Style.hpp>
#include <Gwent/UI/Text.hpp>

namespace {

/**
* private
*/
// clang-format off

static constexpr f32 g_card_width_relative = 0.10f;
static constexpr f32 g_card_aspect_ratio = 775.f / 410.f;
static constexpr f32 g_padding_relative = 0.01f;
static constexpr r::Vec2f g_initial_offset_relative = {0.05f, 0.05f};
static constexpr u8 g_cards_per_row = 3;

/**
 * update systems
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
    r::ecs::ResMut<r::gwent::DeckStats> deck_stats,
    r::ecs::Query<r::ecs::Ref<r::gwent::GwentCard>, r::ecs::Ref<r::gwent::CardPanel>> card_query,
    r::ecs::Query<r::ecs::Mut<r::gwent::Text>, r::ecs::Ref<r::gwent::StatText>> text_query
) {
    *deck_stats.ptr = {};

    for (const auto &[gwent_card, panel] : card_query) {
        if (panel.ptr->current_panel == r::gwent::CardPanel::Panel::SELECTED) {
            deck_stats.ptr->total_cards++;
            const auto card_db_entry = r::gwent::find_card(gwent_card.ptr->id);
            if (card_db_entry.deck == r::gwent::DeckFaction::Special) {
                deck_stats.ptr->special_cards++;
            } else {
                deck_stats.ptr->unit_cards++;
            }
            if (card_db_entry.ability.find("hero") != std::string_view::npos) {
                deck_stats.ptr->hero_cards++;
            }
        }
    }

    for (const auto &[text, stat_marker] : text_query) {
        switch (stat_marker.ptr->type) {
            case r::gwent::StatType::TotalCountValue:   text.ptr->content = std::to_string(deck_stats.ptr->total_cards); break;
            case r::gwent::StatType::UnitCountValue:    text.ptr->content = std::to_string(deck_stats.ptr->unit_cards); break;
            case r::gwent::StatType::SpecialCountValue: text.ptr->content = std::to_string(deck_stats.ptr->special_cards); break;
            case r::gwent::StatType::HeroCountValue:    text.ptr->content = std::to_string(deck_stats.ptr->hero_cards); break;
            default: break;
        }
    }
}

static void update_start_button_click(
    r::ecs::Res<r::UserInput> input,
    r::ecs::Res<r::gwent::DeckStats> deck_stats,
    r::ecs::ResMut<r::NextState<r::gwent::State>> next_state,
    r::ecs::Query<r::ecs::Ref<r::gwent::Style>, r::ecs::Ref<r::gwent::StatText>> button_query
) {
    if (!input.ptr->isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return;
    }

    for (auto [style, stat_marker] : button_query) {

        if (stat_marker.ptr->type != r::gwent::StatType::StartGameButton) {
            continue;
        }

        const auto &mouse = input.ptr->mouse_position;
        const auto &pos = style.ptr->position;
        const auto &size = style.ptr->size;

        const bool inside_x = (mouse.x >= pos.x) && (mouse.x <= pos.x + size.x);
        const bool inside_y = (mouse.y >= pos.y) && (mouse.y <= pos.y + size.y);

        if (inside_x && inside_y) {
            if (deck_stats.ptr->unit_cards >= 22) {
                next_state.ptr->set(r::gwent::State::Playing);
                r::Logger::info("Deck is valid! Changing state to Playing.");
            } else {
                r::Logger::warn("Deck is invalid! You need at least 22 unit cards.");
            }
            break;
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
    r::ecs::EventWriter<r::gwent::CardPanelChangedEvent> event_writer,
    r::ecs::Query<r::ecs::Ref<r::gwent::Style>, r::ecs::Ref<r::gwent::CardPanel>> query
) noexcept
{
    if (!input.ptr->isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return;
    }

    for (auto it = query.begin(); it != query.end(); ++it) {
        const auto [style, panel] = *it;
        const auto &mouse_pos = input.ptr->mouse_position;
        const auto &pos = style.ptr->position;
        const auto &size = style.ptr->size;

        if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.width && 
            mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.height) {

            event_writer.send(r::gwent::CardPanelChangedEvent{
                .card_entity = it.entity(),
                .from = panel.ptr->current_panel,
                .to = (panel.ptr->current_panel == r::gwent::CardPanel::Panel::AVAILABLE)
                    ? r::gwent::CardPanel::Panel::SELECTED
                    : r::gwent::CardPanel::Panel::AVAILABLE
            });

            break;
        }
    }
}

static void update_stats_on_card_move(
    r::ecs::EventReader<r::gwent::CardPanelChangedEvent> event_reader,
    r::ecs::ResMut<r::gwent::DeckStats> deck_stats,
    r::ecs::Query<r::ecs::Mut<r::gwent::CardPanel>, r::ecs::Ref<r::gwent::GwentCard>> query
) {
    for (const auto &event : event_reader) {

        for (auto it = query.begin(); it != query.end(); ++it) {

            if (it.entity() != event.card_entity) {
                continue;
            }

            const auto &[panel, gwent_card] = *it;

            panel.ptr->current_panel = event.to;

            const auto card_data = r::gwent::find_card(gwent_card.ptr->id);
            const bool is_adding_to_deck = (event.to == r::gwent::CardPanel::Panel::SELECTED);

            r::gwent::apply_card_stats(card_data, *deck_stats.ptr, is_adding_to_deck);

            break;
        }
    }
}

static void update_text_from_stats(
    r::ecs::Res<r::gwent::DeckStats> deck_stats,
    r::ecs::Query<r::ecs::Mut<r::gwent::Text>, r::ecs::Ref<r::gwent::StatText>> text_query
)
{
    for (const auto &[text, stat_marker] : text_query) {
        switch (stat_marker.ptr->type) {
            case r::gwent::StatType::TotalCountValue:
                text.ptr->content = std::to_string(deck_stats.ptr->total_cards);
                break;
            case r::gwent::StatType::UnitCountValue:
                text.ptr->content = std::to_string(deck_stats.ptr->unit_cards);
                break;
            case r::gwent::StatType::SpecialCountValue:
                text.ptr->content = std::to_string(deck_stats.ptr->special_cards);
                break;
            case r::gwent::StatType::HeroCountValue:
                text.ptr->content = std::to_string(deck_stats.ptr->hero_cards);
                break;
            case r::gwent::StatType::StrengthCountValue:
                text.ptr->content = std::to_string(deck_stats.ptr->strength);
                break;
            default:
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
        } else {
            index_in_panel = selected_idx++;

            const f32 right_panel_start_x = window_width - content_width_per_panel - padding;

            initial_offset = {right_panel_start_x, padding};
            scroll_offset = scroll_state.ptr->selected_panel.current_offset;
        }

        const u8 row = index_in_panel / g_cards_per_row;
        const u8 col = index_in_panel % g_cards_per_row;

        style.ptr->position = {initial_offset.x + col * (card_width + padding),
            initial_offset.y + row * (card_height + padding) - scroll_offset};
        style.ptr->size = {card_width, card_height};
    }
}

}// namespace

/**
* public
*/

void menu_ui_plugin_update_systems(r::Application &app)
{
    app
        .add_systems<
            update_scrolling_input,
            update_smooth_scrolling,
            update_card_positions,
            update_card_clicking 
        >(r::Schedule::UPDATE)
            .run_if<r::run_conditions::in_state<r::gwent::State::ChoosingDeck>>()

        .add_systems<
            update_stats_on_card_move, 
            update_text_from_stats     
        >(r::Schedule::UPDATE)
            .after<update_card_clicking>()
            .run_if<r::run_conditions::in_state<r::gwent::State::ChoosingDeck>>()

        .add_systems<update_start_button_click>(r::Schedule::UPDATE)
            .after<update_stats_on_card_move>()
            .run_if<r::run_conditions::in_state<r::gwent::State::ChoosingDeck>>();
}
