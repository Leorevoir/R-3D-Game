#pragma once

#include <R-Engine/Core/Backend.hpp>

#include <R-Engine/ECS/Command.hpp>
#include <R-Engine/ECS/Query.hpp>

namespace r {

struct BackgroundData {
        ::Texture2D texture;
};

namespace startup {

void background(ecs::Commands &commands);

}

namespace render {

void background(ecs::Query<ecs::Ref<BackgroundData>> &query) noexcept;

}

namespace shutdown {

void background(ecs::Query<ecs::Ref<BackgroundData>> &query) noexcept;

}

}// namespace r
