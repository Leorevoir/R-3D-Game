#pragma once

#include <R-Engine/Plugins/Plugin.hpp>

#include <Gwent/Card/Decks.hpp>

namespace r {

namespace gwent {

class MenuUIPlugin : public Plugin
{
    public:
        void build(r::Application &app) override;
};

}// namespace gwent

}// namespace r
