#pragma once

// clang-format off

#include "R-Engine/Components/Transform3d.hpp"
#include "R-Engine/Core/FrameTime.hpp"
#include "R-Engine/ECS/Query.hpp"
#include "R-Engine/Plugins/InputPlugin.hpp"

#include "R-Engine/Plugins/RenderPlugin.hpp"
#include "R-Game/Game.hpp"

namespace r {

namespace Update {

void inputs(
    ecs::Res<UserInput> user_input,
    ecs::Res<InputMap> input_map,
    ecs::Query<ecs::Mut<Velocity>, ecs::With<Player>> query
) noexcept;

void player(
    ecs::Res<UserInput> user_input,
    ecs::Res<core::FrameTime> time,
    ecs::Query<ecs::Mut<Transform3d>, ecs::Ref<Velocity>> query,
    ecs::ResMut<Camera3d> camera
) noexcept;

}

}
