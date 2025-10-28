#pragma once

#include <R-Engine/Plugins/Plugin.hpp>

#include <R-Engine/Maths/Vec.hpp>

namespace r {

namespace gwent {

struct WindowSize final {
        Vec2f current = {1920.f, 1080.f};
        Vec2f reference = {1920.f, 1080.f};
        f32 scale_x = 1.f;
        f32 scale_y = 1.f;
        f32 scale_uniform = 1.f;
};

class WindowResizePlugin final : public Plugin
{
    public:
        void build(r::Application &app) override;
};

}// namespace gwent

}// namespace r
