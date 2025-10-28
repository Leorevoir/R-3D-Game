#include <R-Engine/Application.hpp>

#include <R-Engine/Plugins/DefaultPlugins.hpp>
#include <R-Engine/Plugins/WindowPlugin.hpp>

#include <Gwent/Board/Background.hpp>

#include <Gwent/Card/Cards.hpp>

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
 * static helpers
 */

static inline void main_systems_background(r::Application &app)
{
    app.add_systems<r::startup::background>(r::Schedule::STARTUP)
       .add_systems<r::render::background>(r::Schedule::RENDER_2D)
       .add_systems<r::shutdown::background>(r::Schedule::SHUTDOWN);
}

/**
* public
*/

i32 main(void)
{
    r::Application app;

    app.add_plugins(r::DefaultPlugins{}.set(r::WindowPlugin{g_window_config}));

    main_systems_background(app);

    app.run();
}
