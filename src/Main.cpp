#include "R-Engine/Application.hpp"
#include "R-Engine/Plugins/DefaultPlugins.hpp"
#include "R-Engine/Plugins/WindowPlugin.hpp"

#include "R-Game/Startup.hpp"
#include "R-Game/Update.hpp"

// clang-format off

/**
* public
*/

i32 main(void)
{
    r::Application{}

        .add_plugins(r::DefaultPlugins{}.set(
            r::WindowPlugin{
                r::WindowPluginConfig
                {
                    .size = {1920, 1080},
                    .title = "R-Engine - R-Game 3D",
                    .cursor = r::WindowCursorState::Locked
                }
            }
        ))

        .add_systems<
            r::Startup::create_shops,
            r::Startup::create_neons,
            r::Startup::create_player,
            r::Startup::create_inputs
        >(r::Schedule::STARTUP)

        .add_systems<
            r::Update::camera
        >(r::Schedule::FIXED_UPDATE)

        .run();
}
