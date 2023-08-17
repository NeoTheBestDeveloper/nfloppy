#pragma once

#include "entities/entities.hpp"
#include "world_settings.hpp"

namespace Nfloppy {

namespace World {

    class World {

    public:
        World(const int32_t width, const int32_t height);

        void update(const double dt);

        // FIXIT: make private.
        Entities::Entities m_entities;

    private:
        // TODO: Use arena allocator instead of unique_ptr.
        const WorldSettings m_settings;
    };

}

}
