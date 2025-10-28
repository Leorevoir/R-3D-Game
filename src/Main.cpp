#if defined(R_GAME_DEBUG) && !defined(ENGINE_DEBUG)
    #define ENGINE_DEBUG
#endif

#include <R-Engine/Application.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>

#include <Gwent/Plugins/Default.hpp>
#include <Gwent/States.hpp>

/**
* public
*/

i32 main(void)
{
    r::Application{}

        .init_state(r::gwent::State::ChoosingDeck)
        .add_plugins(r::gwent::Default{})
        .run();
}
