#pragma once

#include <R-Engine/Maths/Vec.hpp>

namespace r {

namespace Camera {

struct Angles final {

        f32 yaw = 0.f;
        f32 pitch = 0.f;
};

struct Vectors final {

        Vec3f forward;
        Vec3f right;
};

/**
* getters
*/

Angles &get_angles() noexcept;
Vectors get_vectors(const Angles &angles) noexcept;

/**
* update
*/

void update(Angles &angles, const Vec2f &mouse_delta, f32 sensitivity) noexcept;

}// namespace Camera

}// namespace r
