#include <Gwent/Plugins/TextPlugin.hpp>

#include <Gwent/UI/Style.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/Core/Backend.hpp>

namespace {

/**
* private
*/
// clang-format off

static inline constexpr ::Color rl_color(const r::Color &color) noexcept
{
    return {color.r, color.g, color.b, color.a};
}

static void __text_rendering_impl(const auto *text, const auto *style) noexcept
{
    ::DrawTextEx(
        ::GetFontDefault(),
        text->content.c_str(),
        {style->position.x, style->position.y},
        style->font_size,
        style->spacing,
        rl_color(style->color)
    );
}

/**
 * systems
 */

static void text_rendering_system(
    const r::ecs::Query<r::ecs::Ref<r::gwent::Text>, r::ecs::Ref<r::gwent::Style>> query
)
{
    for (const auto &[text, style] : query) {
        __text_rendering_impl(text.ptr, style.ptr);
    }
}

}

/**
* public
*/

void r::gwent::TextPlugin::build(r::Application &app)
{
    app.add_systems<text_rendering_system>(Schedule::RENDER_2D);
}
