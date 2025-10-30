#pragma once

#include <R-Engine/ECS/Entity.hpp>
#include <R-Engine/Maths/Vec.hpp>
#include <R-Engine/Plugins/Plugin.hpp>

namespace r {

namespace gwent {

struct Game final {
        std::vector<ecs::Entity> hand;
        std::vector<ecs::Entity> deck;
};

struct AnimateToPosition final {
        Vec2f start_pos;
        Vec2f start_size;
        Vec2f target_pos;
        Vec2f target_size;
        f32 duration = 0.5f;
        f32 elapsed_time = 0.0f;
};

class GameUIPlugin final : public Plugin
{
    public:
        void build(r::Application &app) override;
};

}// namespace gwent

}// namespace r
