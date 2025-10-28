#include <Gwent/Plugins/BoardPlugin.hpp>
#include <Gwent/Plugins/ImagePlugin.hpp>
#include <Gwent/Plugins/WindowResizePlugin.hpp>

#include <R-Engine/Application.hpp>

#include <R-Engine/Core/Backend.hpp>
#include <R-Engine/Core/Filepath.hpp>

#include <Gwent/UI/Style.hpp>

namespace {

/**
* private
*/
// clang-format off

/**
* systems
*/

static void startup_background_system(r::ecs::Commands &commands, r::ecs::Res<r::gwent::WindowSize> window_size)
{
    const std::string board_path = "assets/background/board.jpg";

    commands.spawn(
        r::gwent::Image{board_path},
        r::gwent::Style{
            .position = {0.f, 0.f},
            .size = {window_size.ptr->current.x, window_size.ptr->current.y},
            .color = {25, 25, 25, 255},
            .rotation = 0.f,
            .origin = {0.f, 0.f}
        },
        r::gwent::Background{}
    );
}

static void update_background_size_system(
    r::ecs::Query<r::ecs::Mut<r::gwent::Style>, r::ecs::With<r::gwent::Background>> query,
    r::ecs::Res<r::gwent::WindowSize> window_size
) noexcept
{
    for (const auto &[style, _] : query) {
        style.ptr->size.width = window_size.ptr->current.x;
        style.ptr->size.height = window_size.ptr->current.y;
    }
}

}

/**
* public
*/

void r::gwent::BoardPlugin::build(r::Application &app)
{
    app.add_systems<startup_background_system>(r::Schedule::STARTUP)
       .add_systems<update_background_size_system>(r::Schedule::UPDATE);
}

