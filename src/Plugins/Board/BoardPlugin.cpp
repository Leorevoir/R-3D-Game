#include <Gwent/Plugins/BoardPlugin.hpp>
#include <Gwent/Plugins/WindowResizePlugin.hpp>

#include <R-Engine/Application.hpp>

#include <R-Engine/Core/Backend.hpp>
#include <R-Engine/Core/Filepath.hpp>

namespace {

/**
 * private
 */
// clang-format off

struct BackgroundData{
    ::Texture2D texture;
    ::Color color = {25, 25, 25, 255};
};

/**
 * systems
 */

void startup_background(r::ecs::Commands &commands)
{
    const std::string &path = r::path::get("assets/background/board.jpg");

    commands.spawn(
        BackgroundData{
            .texture = ::LoadTexture(path.c_str()),
        }
    );
}

void render_background(r::ecs::Query<r::ecs::Ref<BackgroundData>> &query, r::ecs::Res<r::gwent::WindowSize> window_size) noexcept
{
    static constexpr ::Vector2 origin = {0.f, 0.f};

    for (const auto &[background] : query) {
        const ::Rectangle source = {0.f, 0.f, (f32)background.ptr->texture.width, (f32)background.ptr->texture.height};
        const ::Rectangle dest = {0.f, 0.f, window_size.ptr->current.x, window_size.ptr->current.y};

        ::DrawTexturePro(background.ptr->texture, source, dest, origin, 0.f, background.ptr->color);
    }
}

void shutdown_background(r::ecs::Query<r::ecs::Ref<BackgroundData>> &query) noexcept
{
    for (auto [background] : query) {
        ::UnloadTexture(background.ptr->texture);
    }
}

}

/**
* public
*/

void r::gwent::BoardPlugin::build(r::Application &app)
{
    app.add_systems<startup_background>(r::Schedule::STARTUP)
       .add_systems<render_background>(r::Schedule::RENDER_2D)
       .add_systems<shutdown_background>(r::Schedule::SHUTDOWN);
}

