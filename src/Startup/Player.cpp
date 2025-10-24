#include "R-Game/Game.hpp"
#include "R-Game/Startup.hpp"

// clang-format off

void r::Startup::create_player(ecs::Commands &commands)
{
    commands.spawn(
        Player{},
        Transform3d{
            .position = {0, 2, -24}
        },
        Velocity{
            {.0f, .0f, .0f}
        }
    );
}
