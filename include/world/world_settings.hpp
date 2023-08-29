#pragma once

#include <cstdint>

#include "math/vec2.hpp"

using Nfloppy::Math::Vec2f;

namespace Nfloppy {

namespace World {

    // Contains default values of size and positions for entities.
    class WorldSettings final {

    public:
        WorldSettings();

        const int32_t WORLD_WIDTH = 288;
        const int32_t WORLD_HEIGHT = 512;

        const Vec2f BACKGROUND_POS;
        const Vec2f BACKGROUND_SIZE;

        const Vec2f FPS_COUNTER_POS;
        const Vec2f FPS_COUNTER_SIZE;

        const Vec2f BASE_POS;
        const Vec2f BASE_SIZE;

        const Vec2f BIRD_POS;
        const Vec2f BIRD_SIZE;

        const Vec2f PIPE_POS;
        const Vec2f PIPE_SIZE;

        const double PIPE_SPACING;
        const double PIPE_HOLE;
    };

}

}
