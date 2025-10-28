#include <Gwent/Plugins/Default.hpp>

#include <Gwent/Plugins/TextPlugin.hpp>
#include <Gwent/Plugins/WindowResizePlugin.hpp>
#include <R-Engine/Plugins/InputPlugin.hpp>
#include <R-Engine/Plugins/LuaScriptingPlugin.hpp>
#include <R-Engine/Plugins/MeshPlugin.hpp>
#include <R-Engine/Plugins/RenderPlugin.hpp>
#include <R-Engine/Plugins/TransformPlugin.hpp>
#include <R-Engine/Plugins/WindowPlugin.hpp>

#include <Gwent/Plugins/BoardPlugin.hpp>
#include <Gwent/Plugins/ImagePlugin.hpp>
#include <Gwent/Plugins/MenuUIPlugin.hpp>

#include <R-Engine/Application.hpp>

/**
 * private
 */
// clang-format off

namespace {

static const r::WindowPluginConfig g_window_config
{
    .size = {1920, 1080},
    .title = "R-Engine - R-Game 3D",
    .cursor = r::WindowCursorState::Visible
};

}

/**
* public
*/

r::gwent::Default::Default()
{
    add<WindowPlugin>(g_window_config);
    add<RenderPlugin>();
    add<InputPlugin>();
    add<MeshPlugin>();
    add<TransformPlugin>();
    add<LuaScriptingPlugin>();
    add<r::gwent::WindowResizePlugin>();
    add<r::gwent::ImagePlugin>();
    add<r::gwent::BoardPlugin>();
    add<r::gwent::MenuUIPlugin>();
    add<r::gwent::TextPlugin>();
}

void r::gwent::Default::build(r::Application &app)
{
    PluginGroup::build(app);
}
