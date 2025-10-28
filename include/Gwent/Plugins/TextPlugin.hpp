#pragma once

#include <R-Engine/Plugins/Plugin.hpp>

namespace r {

namespace gwent {

struct Text final {
        std::string content;
};

class TextPlugin : public Plugin
{
    public:
        void build(r::Application &app) override;
};

}// namespace gwent

}// namespace r
