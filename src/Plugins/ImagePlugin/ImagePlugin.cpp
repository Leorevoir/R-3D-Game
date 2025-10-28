#include <Gwent/Plugins/ImagePlugin.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/ECS/Query.hpp>

#include <Gwent/UI/Style.hpp>

namespace {

/**
 * private
 */
// clang-format off

static inline constexpr ::Color rl_color(const r::Color &color) noexcept
{
    return {color.r, color.g, color.b, color.a};
}

template<typename QueryT>
static void __image_rendering_impl(const QueryT &query, r::gwent::ImageManager *image_manager)
{
    for (auto [image, style, _] : query) {
        const auto *texture = image_manager->get(image.ptr->path);

        if (texture) {
            const ::Rectangle dest = {style.ptr->position.x, style.ptr->position.y, style.ptr->size.width, style.ptr->size.height};
            const ::Rectangle source = {0.f, 0.f, (f32) texture->width, (f32) texture->height};
            const ::Vector2 origin = {style.ptr->origin.x, style.ptr->origin.y};

            ::DrawTexturePro(*texture, source, dest, origin, style.ptr->rotation, rl_color(style.ptr->color));
        }
    }
}

/**
 * systems
 */

static void image_rendering_system(
    r::ecs::Query<r::ecs::Ref<r::gwent::Image>, r::ecs::Ref<r::gwent::Style>, r::ecs::Without<r::gwent::Background>> query,
    r::ecs::ResMut<r::gwent::ImageManager> image_manager
)
{
    __image_rendering_impl(query, image_manager.ptr);
}

static void background_rendering_system(
    r::ecs::Query<r::ecs::Ref<r::gwent::Image>, r::ecs::Ref<r::gwent::Style>, r::ecs::With<r::gwent::Background>> query,
    r::ecs::ResMut<r::gwent::ImageManager> image_manager
)
{
    __image_rendering_impl(query, image_manager.ptr);
}

static void unload_textures_system(r::ecs::ResMut<r::gwent::ImageManager> image_manager)
{
    image_manager.ptr->unload();
}

}// anonymous namespace

/**
 * public
 */

void r::gwent::ImagePlugin::build(r::Application &app)
{
    app.insert_resource(ImageManager{})
        .add_systems<image_rendering_system>(Schedule::RENDER_2D)
        .add_systems<background_rendering_system>(Schedule::RENDER_2D).before<image_rendering_system>()
        .add_systems<unload_textures_system>(Schedule::SHUTDOWN);
}
