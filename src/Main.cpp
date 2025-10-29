#if defined(R_GAME_DEBUG) && !defined(ENGINE_DEBUG)
    #define ENGINE_DEBUG
#endif

#include <R-Engine/Application.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>

#include <Gwent/Plugins/Default.hpp>
#include <Gwent/States.hpp>

#include <iostream>

namespace {

/**
 * debug system
 */

#if defined(R_GAME_DEBUG)
static void __debug_system(r::ecs::Res<r::UserInput> input) noexcept
{
    std::cout << "\rpos={" << input.ptr->mouse_position.x << "," << input.ptr->mouse_position.y << "}" << std::flush;
}
#endif

}// namespace

/**
* public
*/

i32 main(void)
{
    r::Application{}

        .init_state(r::gwent::State::ChoosingDeck)
        .add_plugins(r::gwent::Default{})
#if defined(R_GAME_DEBUG)
        .add_systems<__debug_system>(r::Schedule::UPDATE)
#endif
        .run();
}
