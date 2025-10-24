#pragma once

#include <R-Engine/Components/Transform3d.hpp>
#include <R-Engine/Core/FrameTime.hpp>
#include <R-Engine/ECS/Query.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>
#include <R-Engine/Plugins/RenderPlugin.hpp>

#include <R-Game/Game.hpp>

// clang-format off

namespace r {

namespace Update {

void camera(
    ecs::Res<UserInput> user_input,
    ecs::Res<InputMap> input_map,
    ecs::Res<core::FrameTime> time,
    ecs::Query<ecs::Mut<Transform3d>, ecs::Mut<Velocity>, ecs::With<Player>> query,
    ecs::ResMut<Camera3d> camera
) noexcept;

}// namespace Update

}// namespace r
