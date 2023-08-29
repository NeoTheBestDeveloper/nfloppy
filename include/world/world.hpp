#pragma once

#include "entities/entities.hpp"
#include "world/entities/pipe.hpp"
#include "world_settings.hpp"

using Nfloppy::World::Entities::EntityPtr;

namespace Nfloppy {

namespace World {

    class World {

    public:
        World(const int32_t width, const int32_t height);

        World(World const&) = delete;
        World operator=(World const&) = delete;

        void update(const double dt);
        Entities::Entities const& entities() const;

        void jump_bird();
        void activate_bird();

    private:
        Entities::Entities m_entities;
        const WorldSettings m_settings;

        const int32_t m_width;
        const int32_t m_height;
    };

}

}
