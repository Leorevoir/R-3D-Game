#include <R-Engine/Application.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>

#include <Gwent/Plugins/Default.hpp>
#include <Gwent/States.hpp>

#include <iostream>

/**
 * debug
 */

static void debug_system(r::ecs::Res<r::UserInput> input_ptr)
{
    const auto &input = input_ptr.ptr;

    std::cout << "\rmouse={" << input->mouse_position.x << ", " << input->mouse_position.y << "}" << std::flush;
}

/**
* public
*/

i32 main(void)
{
    r::Application{}

        .init_state(r::gwent::State::ChoosingDeck)
        .add_plugins(r::gwent::Default{})
        .add_systems<debug_system>(r::Schedule::UPDATE)
        .run();
}
