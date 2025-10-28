#include <Gwent/Plugins/WindowResizePlugin.hpp>

#include <R-Engine/Core/Backend.hpp>
#include <R-Engine/Core/Logger.hpp>

#include <R-Engine/Application.hpp>

/**
* private
*/
// clang-format off

namespace {

static void update_window_size(r::ecs::ResMut<r::gwent::WindowSize> window_size) noexcept
{
    const i32 width = ::GetScreenWidth();
    const i32 height = ::GetScreenHeight();

    if (window_size.ptr->current != r::Vec2f{(f32)width, (f32)height}) {
        window_size.ptr->current = {(f32)width, (f32)height};
        window_size.ptr->scale_x = (f32)width / window_size.ptr->reference.x;
        window_size.ptr->scale_y = (f32)height / window_size.ptr->reference.y;
        window_size.ptr->scale_uniform = std::min(window_size.ptr->scale_x, window_size.ptr->scale_y);
    }
}

}

/**
* public
*/

void r::gwent::WindowResizePlugin::build(r::Application &app)
{
    app.insert_resource(r::gwent::WindowSize{})
       .add_systems<update_window_size>(r::Schedule::UPDATE);
}
