#pragma once

#include <random>

#include "entities/entities.hpp"
#include "world/entities/pipe.hpp"
#include "world_settings.hpp"

using Nfloppy::World::Entities::EntityPtr;
using Nfloppy::World::Entities::PipeDirection;

namespace Nfloppy {

namespace World {

    class World {

    public:
        World(const int32_t width, const int32_t height);

        World(World const&) = delete;
        World operator=(World const&) = delete;

        void update(const double dt);
        Entities::Entities const& entities() const;

    private:
        Entities::Entities m_entities;
        const WorldSettings m_settings;

        const int32_t m_width;
        const int32_t m_height;

        std::mt19937 m_gen;
        std::uniform_int_distribution<std::mt19937::result_type> m_dis;

        EntityPtr make_background() const;
        EntityPtr make_base() const;
        EntityPtr make_bird() const;
        EntityPtr make_tube(EntityId id) const;
        void make_tubes();

        PipeDirection get_pipe_direction(EntityId id) const;

        double get_up_pipe_y(double up_pipe_heigth) const;
        double get_down_pipe_y(double up_pipe_heigth) const;

        double gen_up_pipe_heigth();

        void init_level();
    };

}

}
