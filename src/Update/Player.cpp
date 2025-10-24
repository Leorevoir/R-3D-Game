#include <R-Game/Camera.hpp>
#include <R-Game/Update.hpp>

/**
 * static helpers
 */

static constexpr f32 G_MOUSE_SENSITIVITY = 0.1f;

/**
* public
*/

void r::Update::player(ecs::Res<UserInput> user_input, ecs::Res<core::FrameTime> time,
    ecs::Query<ecs::Mut<Transform3d>, ecs::Ref<Velocity>> query, ecs::ResMut<Camera3d> camera) noexcept
{
    auto &angles = Camera::get_angles();
    Camera::update(angles, user_input.ptr->mouse_delta, G_MOUSE_SENSITIVITY);

    const auto vectors = Camera::get_vectors(angles);

    for (auto [transform, velocity] : query) {
        transform.ptr->position += *velocity.ptr * time.ptr->delta_time;
        const Vec3f &player_pos = transform.ptr->position;

        camera.ptr->position = player_pos;
        camera.ptr->target = player_pos + vectors.forward;
        break;
    }
}
