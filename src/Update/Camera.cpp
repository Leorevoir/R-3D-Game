#include <R-Game/Camera.hpp>
#include <R-Game/Update.hpp>
#include <iostream>

/**
 * static helpers
 */

static constexpr f32 G_MOUSE_SENSITIVITY = 0.1f;
static constexpr f32 G_PLAYER_SPEED = 10.f;
static constexpr r::Vec3f G_UP = {0.f, 1.f, 0.f};

/**
* public
*/
// clang-format off

void r::Update::camera(
    ecs::Res<UserInput> user_input,
    ecs::Res<InputMap> input_map,
    ecs::Res<core::FrameTime> time,
    ecs::Query<ecs::Mut<Transform3d>, ecs::Mut<Velocity>, ecs::With<Player>> query,
    ecs::ResMut<Camera3d> camera
) noexcept
{

    auto &angles = Camera::get_angles();
    Camera::update(angles, user_input.ptr->mouse_delta, G_MOUSE_SENSITIVITY);

    const auto vectors = Camera::get_vectors(angles);

    const auto *map = input_map.ptr;
    const auto &input = *user_input.ptr;
    Vec3f dir = {0.f, 0.f, 0.f};

    if (map->isActionPressed("MoveForward", input)) {
        dir += vectors.forward;
    }
    if (map->isActionPressed("MoveBackward", input)) {
        dir -= vectors.forward;
    }
    if (map->isActionPressed("MoveLeft", input)) {
        dir += vectors.right;
    }
    if (map->isActionPressed("MoveRight", input)) {
        dir -= vectors.right;
    }
    if (map->isActionPressed("MoveUp", input)) {
        dir += G_UP;
    }
    if (map->isActionPressed("MoveDown", input)) {
        dir -= G_UP;
    }

    const Vec3f final_velocity = dir.normalize() * G_PLAYER_SPEED;

    for (auto [transform, velocity, _] : query) {

        *velocity.ptr = final_velocity;

        transform.ptr->position += *velocity.ptr * time.ptr->delta_time;
        const Vec3f &player_pos = transform.ptr->position;

        std::cout << "\rpos={" 
          << player_pos.x << ", " 
          << player_pos.y << ", " 
          << player_pos.z << "}" 
          << std::flush;

        camera.ptr->position = player_pos;
        camera.ptr->target = player_pos + vectors.forward;
        break;
    }
}
