#include <R-Engine/Core/Filepath.hpp>

#include <R-Game/Game.hpp>
#include <R-Game/Startup.hpp>

/**
 * private
 */

namespace {

// clang-format off

static constexpr struct {
    const char *model_path;
    r::Transform3d transform;
} shops[] = {
    {
        .model_path = "assets/models/Shop-0-ShopBuilding_1.obj",
        .transform  = {
            .position = { 0.f, 4.f, 0.f },
            .rotation = { 0.f, 0.f, 0.f },
            .scale    = { 1.f, 1.f, 1.f }
        }
    },
    {
        .model_path = "assets/models/Shop-1-ShopBuilding_2.obj",
        .transform  = {
            .position = { -14.f, 3.5f, -5.f },
            .rotation = { 0.f, 0.f, 0.f },
            .scale    = { 1.f, 1.f, 1.f }
        }
    },
    {
        .model_path = "assets/models/Shop-4-GroundTile.obj",
        .transform  = {
            .position = { -2.f, 0.f, -8.f },
            .rotation = { 0.f, 0.f, 0.f },
            .scale    = { 1.f, 1.f, 1.f }
        }
    },
    {
        .model_path = "assets/models/Shop-4-GroundTile.obj",
        .transform  = {
            .position = { -22.f, 0.f, -8.f },
            .rotation = { 0.f, 0.f, 0.f},
            .scale    = { 1.f, 1.f, 1.f }
        }
    },
};

}// namespace

/**
* public
*/

void r::Startup::create_shops(ecs::Commands &commands, ecs::ResMut<Meshes> meshes)
{
    for (const auto &shop : shops) {
        const auto &real_path = path::get(shop.model_path);

        commands.spawn(
            Shop{},
            Mesh3d{
                meshes.ptr->add(Mesh3d::Glb(real_path)),
            },
            Transform3d{
                shop.transform
            }
        );
    }
}
