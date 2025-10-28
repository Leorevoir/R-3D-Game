#include <Gwent/Plugins/ImagePlugin.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/ECS/Query.hpp>

/**
 * private
 */
// clang-format off

namespace {

static void image_rendering_system(
    r::ecs::Query<r::ecs::Ref<r::gwent::Image>, r::ecs::Ref<r::gwent::Style>> query,
    r::ecs::ResMut<r::gwent::ImageManager> image_manager
)
{
    for (auto [image, style] : query) {
        const auto *texture = image_manager.ptr->get(image.ptr->path);

        if (texture) {
            const ::Rectangle dest = {style.ptr->position.x, style.ptr->position.y, style.ptr->size.width, style.ptr->size.height};
            const ::Rectangle source = {0.f, 0.f, (f32) texture->width, (f32) texture->height};

            DrawTexturePro(*texture, source, dest, {0, 0}, 0.f, WHITE);
        }
    }
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
        .add_systems<unload_textures_system>(Schedule::SHUTDOWN);

    r::Logger::info("ImagePlugin built and loaded successfully.");
}
