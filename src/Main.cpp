#include <R-Engine/Application.hpp>

#include <R-Engine/Plugins/DefaultPlugins.hpp>
#include <R-Engine/Plugins/WindowPlugin.hpp>

/**
 * private
 */
// clang-format off

static const r::WindowPluginConfig g_window_config
{
    .size = {1920, 1080},
    .title = "R-Engine - R-Game 3D",
    .cursor = r::WindowCursorState::Locked
};

/**
* public
*/

i32 main(void)
{
    r::Application{}

        .add_plugins(r::DefaultPlugins{}.set(g_window_config))

        .add_systems<
        >(r::Schedule::STARTUP)

        .run();
}
