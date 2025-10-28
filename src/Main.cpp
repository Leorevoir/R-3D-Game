#include <R-Engine/Application.hpp>

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
