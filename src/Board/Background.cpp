#include <Gwent/Board/Background.hpp>

#include <R-Engine/Core/Filepath.hpp>

/**
 * private
 */
// clang-format off

namespace {


}// namespace

/**
* public
*/

void r::startup::background(ecs::Commands &commands)
{
    const std::string &path = path::get("assets/background/board.jpg");

    commands.spawn(
        BackgroundData{
            .texture = ::LoadTexture(path.c_str())
        }
    );
}

void r::render::background(ecs::Query<ecs::Ref<BackgroundData>> &query) noexcept
{
    for (auto [background] : query) {
        ::DrawTexture(background.ptr->texture, 0, 0, ::WHITE);
    }
}

void r::shutdown::background(ecs::Query<ecs::Ref<BackgroundData>> &query) noexcept
{
    for (auto [background] : query) {
        ::UnloadTexture(background.ptr->texture);
    }
}
