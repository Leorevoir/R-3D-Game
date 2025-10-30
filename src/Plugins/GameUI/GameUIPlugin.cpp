#include <Gwent/Plugins/GameUIPlugin.hpp>

/**
 * import
 */

void game_ui_plugin_build_game_ui_animation(r::Application &app);

/**
* public
*/

void r::gwent::GameUIPlugin::build(r::Application &app)
{
    game_ui_plugin_build_game_ui_animation(app);
}
