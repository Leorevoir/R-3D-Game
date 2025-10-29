#pragma once

#include <R-Engine/Plugins/Plugin.hpp>

namespace r {

namespace gwent {

class CarouselPlugin final : public Plugin
{
    public:
        void build(Application &app) override;
};

}// namespace gwent

}// namespace r
