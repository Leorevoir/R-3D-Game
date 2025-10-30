#pragma once

#include <R-Engine/ECS/Entity.hpp>
#include <R-Engine/Plugins/Plugin.hpp>

namespace r {

namespace gwent {

struct CarouselState final {
        std::vector<ecs::Entity> hand;
        std::vector<ecs::Entity> deck;
        u8 swaps_left = 2;
};

class CarouselPlugin final : public Plugin
{
    public:
        void build(Application &app) override;
};

}// namespace gwent

}// namespace r
