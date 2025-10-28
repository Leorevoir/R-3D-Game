#pragma once

#include <R-Engine/Maths/Vec.hpp>

namespace r {

namespace gwent {

struct Style {
        Vec2f position = {0.f, 0.f};
        Vec2f size = {100.f, 100.f};
        Color color = {255, 255, 255, 255};
        f32 rotation = 0.f;
        Vec2f origin = {0.f, 0.f};
        f32 font_size = 20.f;
        f32 spacing = 1.f;

        inline Style operator=(const Style &other) const noexcept
        {
            Style result = *this;

            result.position = other.position;
            result.size = other.size;
            return result;
        }
};

enum class Visibility { Visible, Hidden };

}// namespace gwent

}// namespace r
