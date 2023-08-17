#pragma once

#include <cstdint>

#include "math/vec2.hpp"

namespace Nfloppy {

namespace World {

    // Contains default values of size and positions for entities.
    class WorldSettings final {
        friend class World;

    public:
        WorldSettings(const int32_t width, const int32_t height);

    private:
        const Math::Vec2f BACKGROUND_POS;
        const Math::Vec2f BACKGROUND_SIZE;

        const Math::Vec2f FPS_COUNTER_POS;
        const Math::Vec2f FPS_COUNTER_SIZE;

        const Math::Vec2f BASE_POS;
        const Math::Vec2f BASE_SIZE;

        const Math::Vec2f BIRD_POS;
        const Math::Vec2f BIRD_SIZE;
    };

}

}
