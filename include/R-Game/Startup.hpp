#pragma once

#include <R-Engine/Components/Shader.hpp>
#include <R-Engine/ECS/Command.hpp>
#include <R-Engine/ECS/Query.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>
#include <R-Engine/Plugins/MeshPlugin.hpp>

// clang-format off

namespace r {

namespace Startup {

void create_player(ecs::Commands &commands);
void create_inputs(ecs::ResMut<InputMap> input_map);

}// namespace Startup

}// namespace r
