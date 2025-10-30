#include <Gwent/Plugins/CarouselPlugin.hpp>
#include <Gwent/Plugins/GameUIPlugin.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/Core/FrameTime.hpp>
#include <R-Engine/Core/Logger.hpp>
#include <R-Engine/Core/States.hpp>
#include <R-Engine/ECS/Query.hpp>

#include <Gwent/States.hpp>
#include <Gwent/UI/Style.hpp>

/**
 * export
 */

void game_ui_plugin_build_game_ui_animation(r::Application &app);

namespace {

/**
 * g_constants
 */

static constexpr const f32 g_target_card_width = 180.f * (410.f / 775.f);
static constexpr const f32 g_hand_width = 1500.f - 580.f;
static constexpr const f32 g_visible_card_width_step = g_target_card_width * 0.7f;
static constexpr const f32 g_total_hand_layout_width = (10 - 1) * g_visible_card_width_step + g_target_card_width;
static constexpr const f32 g_hand_start_x = 580.f + (g_hand_width - g_total_hand_layout_width) / 2.0f;

/**
* private
*/
// clang-format off

static inline void __animate_card_to_position(
    r::ecs::Commands &commands,
    const r::ecs::Entity card_entity,
    const r::Vec2f &start_pos,
    const r::Vec2f &target_pos,
    const r::Vec2f &start_size,
    const r::Vec2f &target_size
)
{
    commands.entity(card_entity).insert(r::gwent::AnimateToPosition{
        .start_pos = start_pos,
        .start_size = start_size,
        .target_pos = target_pos,
        .target_size = target_size
    });
}

static inline void __set_cards_startup_animation(
    r::ecs::Commands &commands,
    const auto &hand,
    r::ecs::Query<r::ecs::Mut<r::gwent::Style>> &style_query
)
{
    for (u32 i = 0; i < 10; ++i) {
        const auto card_entity = hand[i];

        for (auto it = style_query.begin(); it != style_query.end(); ++it) {

            if (it.entity() != card_entity) {
                continue;
            }

            const auto &[style] = *it;
            const r::Vec2f target_pos
            {
                g_hand_start_x + (i * g_visible_card_width_step),
                850.f
            };

            __animate_card_to_position(
                commands,
                card_entity,
                style.ptr->position,
                target_pos,
                style.ptr->size,
                {g_target_card_width, 180.f}
            );
            break;
        }
    }
}

/**
 * systems
 */

static void setup_game_state_and_animate_cards_system(
    r::ecs::Commands &commands,
    const r::ecs::Res<r::gwent::CarouselState> carousel_state,
    r::ecs::Query<r::ecs::Mut<r::gwent::Style>> style_query
)
{
    const auto game_state = r::gwent::Game
    {
        .hand = carousel_state.ptr->hand,
        .deck = carousel_state.ptr->deck
    };

    commands.insert_resource(game_state);
    __set_cards_startup_animation(commands, game_state.hand, style_query);
    commands.remove_resource<r::gwent::CarouselState>();
}


static void update_card_animation_system(
    r::ecs::Commands &commands,
    const r::ecs::Res<r::core::FrameTime> frame_time,
    r::ecs::Query<r::ecs::Mut<r::gwent::AnimateToPosition>, r::ecs::Mut<r::gwent::Style>> query
) noexcept
{
    for (auto it = query.begin(); it != query.end(); ++it) {
        const auto &[anim, style] = *it;
        const r::ecs::Entity entity = it.entity();

        anim.ptr->elapsed_time += frame_time.ptr->delta_time;
        
        const f32 progress = std::min(anim.ptr->elapsed_time / anim.ptr->duration, 1.0f);

        style.ptr->position.x = std::lerp(anim.ptr->start_pos.x, anim.ptr->target_pos.x, progress);
        style.ptr->position.y = std::lerp(anim.ptr->start_pos.y, anim.ptr->target_pos.y, progress);
        style.ptr->size.width = std::lerp(anim.ptr->start_size.width, anim.ptr->target_size.width, progress);
        style.ptr->size.height = std::lerp(anim.ptr->start_size.height, anim.ptr->target_size.height, progress);
    }
}

} //namespace

/**
* public
*/

void game_ui_plugin_build_game_ui_animation(r::Application &app)
{
    app
        .add_systems<setup_game_state_and_animate_cards_system>(r::OnEnter{r::gwent::State::Playing})
        .add_systems<update_card_animation_system>(r::Schedule::UPDATE)
            .run_if<r::run_conditions::in_state<r::gwent::State::Playing>>();
}
