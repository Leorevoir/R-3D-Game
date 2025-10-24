#include <R-Engine/Core/Filepath.hpp>

#include <R-Game/Game.hpp>
#include <R-Game/Maths.hpp>
#include <R-Game/Startup.hpp>

/**
 * private
 */
// clang-format off

namespace {

static constexpr f32 G_CYL_RADIUS = 0.1f;
static constexpr i32 G_CYL_SIDES = 24;

static constexpr struct {
    struct {
        const char *vert;
        const char *frag;
    } shader;
    f32 length;
    r::Transform3d transform;
} neons[] = {
    {
        .shader = {
            .vert   = "assets/shaders/neons/neon_shader.vert",
            .frag   = "assets/shaders/neons/neon_shader.frag",
        },
        .length = 12.6f,
        .transform  = {
            .position = { 5.6f, 4.6f, -2.f },
            .rotation = { 0.f, 0.f, r::G_PI_2F },
            .scale    = { 1.f, 1.f, 1.f }
        }
    }
};

/**
 * static helpers
 */

static inline auto create_neons_mesh(const f32 length)
{
    return ::GenMeshCylinder(G_CYL_RADIUS, length, G_CYL_SIDES);
}

static inline r::Material3d create_neon_material(const auto &shaders, const std::string &vert_path, const std::string &frag_path)
{
    const r::ShaderHandle shader_handle = shaders.ptr->load(vert_path, frag_path);

    return r::Material3d{shader_handle};
}

}

/**
* public
*/

void r::Startup::create_neons(
    ecs::Commands &commands,
    ecs::ResMut<Meshes> meshes,
    ecs::ResMut<Shaders> shaders,
    ecs::Res<core::FrameTime> frame_time
)
{
    for (const auto &neon : neons) {

        const std::string &vert_path = path::get(neon.shader.vert);
        const std::string &frag_path = path::get(neon.shader.frag);

        commands.spawn(
            Neon{},
            Mesh3d{
                meshes.ptr->add(create_neons_mesh(neon.length)),
                ::r::Color{0, 128, 0}
            },
            Transform3d{
                neon.transform
            },
            Material3d{
                create_neon_material(shaders, vert_path, frag_path),
            }
        );
    }
}
