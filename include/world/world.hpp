#pragma once

#include "entities/entities.hpp"
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
        const Entities::Entities& entities() const;

    private:
        Entities::Entities m_entities;
        const WorldSettings m_settings;

        EntityPtr make_background() const;
        EntityPtr make_base() const;
        EntityPtr make_bird() const;
    };

}

}
