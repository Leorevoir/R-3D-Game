#include <Gwent/Plugins/BoardPlugin.hpp>

#include <R-Engine/Application.hpp>

#include <R-Engine/Core/Backend.hpp>
#include <R-Engine/Core/Filepath.hpp>

/**
* private
*/
// clang-format off

namespace {

struct BackgroundData{::Texture2D texture;};

void startup_background(r::ecs::Commands &commands)
{
    const std::string &path = r::path::get("assets/background/board.jpg");

    commands.spawn(
        BackgroundData{
            .texture = ::LoadTexture(path.c_str())
        }
    );
}

void render_background(r::ecs::Query<r::ecs::Ref<BackgroundData>> &query) noexcept
{
    for (auto [background] : query) {
        ::DrawTexture(background.ptr->texture, 0, 0, ::WHITE);
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
