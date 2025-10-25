#pragma once

#include "R-Engine/Maths/Vec.hpp"

namespace r {

/**
* game components
*/

struct Player final {
};
struct Velocity final : public Vec3f {

        constexpr inline const Velocity &operator=(const Vec3f &other) noexcept
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
};

}// namespace r
