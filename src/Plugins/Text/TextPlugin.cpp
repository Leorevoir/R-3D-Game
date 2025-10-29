#include <Gwent/Plugins/TextPlugin.hpp>
#include <Gwent/Plugins/WindowResizePlugin.hpp>

#include <Gwent/UI/RenderLayers.hpp>
#include <Gwent/UI/Style.hpp>
#include <Gwent/UI/Text.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/Core/Backend.hpp>
#include <R-Engine/Core/Filepath.hpp>

namespace {

/**
 * private
 */
// clang-format off

struct TextFont final {
    ::Font data = {};
};

static const std::string g_font_path = r::path::get("assets/fonts/arial.ttf");

static inline const auto __get_text_size(const r::gwent::Text *text, const r::gwent::Style *style, const TextFont *font) noexcept
{
    return ::MeasureTextEx(font->data, text->content.c_str(), style->font_size, style->spacing);
}

static inline void __draw_text(const r::gwent::Text *text, const r::gwent::Style *style, const r::Vec2f &position, const TextFont *font) noexcept
{
    ::DrawTextEx(
        font->data,
        text->content.c_str(),
        {
            .x = position.x,
            .y = position.y
        },
        style->font_size,
        style->spacing,
        {
            .r = style->color.r,
            .g = style->color.g,
            .b = style->color.b,
            .a = style->color.a
        }
    );
}

/**
 * systems
 */

static void update_text_layout_system(
    r::ecs::Query<r::ecs::Mut<r::gwent::Style>, r::ecs::Ref<r::gwent::Text>, r::ecs::Ref<r::gwent::TextLayout>> query,
    r::ecs::Res<r::gwent::WindowSize> window_size,
    r::ecs::Res<TextFont> font
) {
    for (const auto &[style, text, layout] : query) {
        const auto text_size = __get_text_size(text.ptr, style.ptr, font.ptr);
        const r::Vec2f base_pos = {
            window_size.ptr->current.x * layout.ptr->relative_position.x,
            window_size.ptr->current.y * layout.ptr->relative_position.y
        };
        const r::Vec2f pivot_offset = {
            text_size.x * layout.ptr->pivot.x,
            text_size.y * layout.ptr->pivot.y
        };

        style.ptr->position = base_pos - pivot_offset + layout.ptr->offset;
        style.ptr->size = {
            text_size.x,
            text_size.y
        };
    }
}

static void render_text_system(
    r::ecs::Query<
        r::ecs::Ref<r::gwent::Text>,
        r::ecs::Ref<r::gwent::Style>,
        r::ecs::Optional<r::gwent::Visibility>
    > query,
    r::ecs::Res<TextFont> font
) noexcept
{
    for (const auto &[text, style, visibility_opt] : query) {

        if (visibility_opt.ptr && *visibility_opt.ptr == r::gwent::Visibility::Hidden) {
            continue;
        }

        __draw_text(text.ptr, style.ptr, style.ptr->position, font.ptr);
    }
}

static void startup_system(r::ecs::ResMut<TextFont> font_res) noexcept
{
    font_res.ptr->data = ::LoadFont(g_font_path.c_str());
}

static void shutdown_system(r::ecs::ResMut<TextFont> font_res) noexcept
{
    if (font_res.ptr->data.texture.id != 0) {
        ::UnloadFont(font_res.ptr->data);
    }
}

} // namespace

void r::gwent::TextPlugin::build(r::Application &app)
{
    app
       .insert_resource(TextFont{})
       .add_systems<startup_system>(Schedule::STARTUP)
       .add_systems<update_text_layout_system>(Schedule::UPDATE)
       .add_systems<render_text_system>(Schedule::RENDER_2D)
           .in_set<__TextSet>()
       .add_systems<shutdown_system>(Schedule::SHUTDOWN);
}
