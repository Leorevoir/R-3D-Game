#include "R-Engine/Components/Transform3d.hpp"
#include "R-Engine/Core/Filepath.hpp"

#include "R-Engine/Plugins/MeshPlugin.hpp"
#include "R-Game/Game.hpp"
#include "R-Game/Startup.hpp"

/**
 * private
 */

namespace {

// clang-format off

static constexpr const char *shops[] = 
{
    "assets/models/Shop-0-ShopBuilding_1.obj",
    "assets/models/Shop-1-ShopBuilding_2.obj"
};

}

/**
* public
*/

void r::Startup::create_map(ecs::Commands &commands, ecs::ResMut<Meshes> meshes)
{
    for (const auto &raw_path : shops) {
        const auto &real_path = path::get(raw_path);

        commands.spawn(
            Mesh3d{
                meshes.ptr->add(Mesh3d::Glb(real_path)),
            },
            Transform3d{
                .position = {.0f, .0f, .0f},
                .scale = {1.f, 1.f, 1.f}
            }
        );
    }
}
