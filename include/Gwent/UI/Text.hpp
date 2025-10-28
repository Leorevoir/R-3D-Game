#pragma once

#include <R-Engine/Maths/Vec.hpp>

#include <string>

namespace r {

namespace gwent {

struct Text final {
        std::string content;
};

enum class HAlign { Left, Center, Right };
enum class VAlign { Top, Center, Bottom };

struct TextLayout {
        Vec2f pivot = {0.0f, 0.0f};
        Vec2f relative_position = {0.0f, 0.0f};
        Vec2f offset = {0.0f, 0.0f};
};

}// namespace gwent

}// namespace r
