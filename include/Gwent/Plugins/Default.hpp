#pragma once

#include <R-Engine/Plugins/Plugin.hpp>

namespace r {

namespace gwent {

class Default final : public PluginGroup
{
    public:
        Default();

        void build(Application &app) override;
};

}// namespace gwent

}// namespace r
