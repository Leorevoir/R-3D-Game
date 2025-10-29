#include <Gwent/Plugins/CarouselPlugin.hpp>
#include <Gwent/Plugins/WindowResizePlugin.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/Core/Backend.hpp>
#include <R-Engine/Core/Logger.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>

#include <Gwent/States.hpp>
#include <Gwent/UI/DeckBuilder.hpp>
#include <Gwent/UI/Style.hpp>
#include <Gwent/UI/Text.hpp>

#include <algorithm>
#include <random>
#include <vector>

namespace {

/**
 * private
 */
// clang-format off

/**
 * @brief Tag component for cards currently in the carousel hand.
 */
struct CarouselCard final {
};

/**
 * @brief Tag component for the carousel's confirm button.
 */
struct ConfirmButton final {
};

/**
 * @brief Resource to manage the state of the carousel/mulligan phase.
 */
struct CarouselState final {
        std::vector<r::ecs::Entity> hand;
        std::vector<r::ecs::Entity> deck;
        u8 swaps_left = 2;
};

static inline void __shuffle(std::vector<r::ecs::Entity> &entities)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(entities.begin(), entities.end(), g);
}

/**
 * systems
 */

static void startup_carousel_system(r::ecs::Commands &commands, r::ecs::Query<r::ecs::Ref<r::gwent::CardPanel>> query)
{
    std::vector<r::ecs::Entity> selected_deck;

    for (auto it = query.begin(); it != query.end(); ++it) {
        const auto [panel] = *it;

        if (panel.ptr->current_panel == r::gwent::CardPanel::Panel::SELECTED) {
            selected_deck.push_back(it.entity());
        }
    }

    if (selected_deck.size() < 10) {
        r::Logger::error("Deck has less than 10 cards, cannot start carousel.");
        return;
    }

    __shuffle(selected_deck);

    auto carousel_state = CarouselState{};
    for (size_t i = 0; i < 10; ++i) {
        carousel_state.hand.push_back(selected_deck[i]);
    }
    for (size_t i = 10; i < selected_deck.size(); ++i) {
        carousel_state.deck.push_back(selected_deck[i]);
    }

    for (const auto &card_entity : carousel_state.hand) {
        commands.entity(card_entity).insert(CarouselCard{}).insert(r::gwent::Visibility::Visible);
    }

    commands.spawn(
        r::gwent::Text{
            .content = "Confirm Hand"
        },
        r::gwent::Style{
            .color = {200, 180, 100, 255},
            .font_size = 36.f
        },
        r::gwent::TextLayout{
            .pivot = {0.5f, 0.5f},
            .relative_position = {0.5f, 0.9f}
        },
        ConfirmButton{}
    );
    commands.insert_resource(carousel_state);
}

static void update_carousel_card_positions_system(
    r::ecs::Query<r::ecs::Mut<r::gwent::Style>, r::ecs::With<CarouselCard>> query,
    r::ecs::Res<r::gwent::WindowSize> window_size
) noexcept
{
    const f32 card_width = window_size.ptr->current.x * 0.08f;
    const f32 card_height = card_width * (775.f / 410.f);
    const f32 total_width = query.size() * card_width;
    const f32 start_x = (window_size.ptr->current.x - total_width) / 2.0f;
    const f32 y_pos = (window_size.ptr->current.y - card_height) / 2.0f;

    u32 i = 0;

    for (const auto &[style, _] : query) {
        style.ptr->position = {
            start_x + (i * card_width),
            y_pos
        };
        style.ptr->size = {
            card_width,
            card_height
        };
        ++i;
    }
}

static void handle_card_swap_system(
    r::ecs::Commands &commands,
    r::ecs::Res<r::UserInput> input,
    r::ecs::ResMut<CarouselState> carousel_state,
    r::ecs::Query<r::ecs::Ref<r::gwent::Style>, r::ecs::With<CarouselCard>> query
)
{
    if (!input.ptr->isMouseButtonPressed(MOUSE_BUTTON_LEFT) || carousel_state.ptr->swaps_left == 0 || carousel_state.ptr->deck.empty()) {
        return;
    }

    for (auto it = query.begin(); it != query.end(); ++it) {
        const auto [style, _] = *it;
        const auto &mouse_pos = input.ptr->mouse_position;
        const auto &pos = style.ptr->position;
        const auto &size = style.ptr->size;

        if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.width && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.height) {

            --carousel_state.ptr->swaps_left;

            const r::ecs::Entity entity_to_remove = it.entity();
            const r::ecs::Entity entity_to_add = carousel_state.ptr->deck.back();
            carousel_state.ptr->deck.pop_back();

            commands.entity(entity_to_remove).remove<CarouselCard>();
            commands.entity(entity_to_add).insert(CarouselCard{}).insert(r::gwent::Visibility::Visible);

            auto &hand = carousel_state.ptr->hand;
            const auto hand_it = std::find(hand.begin(), hand.end(), entity_to_remove);

            if (hand_it != hand.end()) {
                *hand_it = entity_to_add;
            }

            carousel_state.ptr->deck.push_back(entity_to_remove);

            r::Logger::info("Card swapped. " + std::to_string(carousel_state.ptr->swaps_left) + " swaps remaining.");
            break;
        }
    }
}

static void handle_confirm_button_click_system(
    r::ecs::Res<r::UserInput> input,
    r::ecs::ResMut<r::NextState<r::gwent::State>> next_state,
    r::ecs::Query<r::ecs::Ref<r::gwent::Style>, r::ecs::With<ConfirmButton>> query
) noexcept
{
    if (!input.ptr->isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return;
    }

    for (const auto &[style, _] : query) {
        const auto &mouse = input.ptr->mouse_position;
        const auto &pos = style.ptr->position;
        const auto &size = style.ptr->size;

        if ((mouse.x >= pos.x && mouse.x <= pos.x + size.x) && (mouse.y >= pos.y && mouse.y <= pos.y + size.y)) {
            r::Logger::info("Hand confirmed. Transitioning to Playing state.");
            next_state.ptr->set(r::gwent::State::Playing);
            break;
        }
    }
}

static void cleanup_carousel_system(r::ecs::Commands &commands, r::ecs::Query<r::ecs::With<ConfirmButton>> button_query)
{
    r::Logger::debug("Cleaning up carousel UI.");

    for (auto it = button_query.begin(); it != button_query.end(); ++it) {
        commands.despawn(it.entity());
    }
    commands.remove_resource<CarouselState>();
}

}// anonymous namespace

void r::gwent::CarouselPlugin::build(r::Application &app)
{
    app
        .add_systems<startup_carousel_system>(OnEnter{State::Carousel})
        .add_systems<cleanup_carousel_system>(OnExit{State::Carousel})
        .add_systems<update_carousel_card_positions_system, handle_card_swap_system, handle_confirm_button_click_system>(Schedule::UPDATE)
        .run_if<r::run_conditions::in_state<State::Carousel>>();
}
