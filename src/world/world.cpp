#include "world/world.hpp"
#include "world/entities/background.hpp"
#include "world/entities/base.hpp"
#include "world/entities/bird.hpp"
#include "world/entities/entity_id.hpp"
#include "world/entities/pipe.hpp"

using Nfloppy::World::World;
using Nfloppy::World::Entities::Background;
using Nfloppy::World::Entities::Base;
using Nfloppy::World::Entities::Bird;
using Nfloppy::World::Entities::Entities;
using Nfloppy::World::Entities::EntityId;
using Nfloppy::World::Entities::Pipe;

World::World(const int32_t width, const int32_t height)
    : m_entities(6)
    , m_width(width)
    , m_height(height)
{
    m_entities[EntityId::BACKGROUND] = std::make_unique<Background>();
    m_entities[EntityId::BASE] = std::make_unique<Base>();
    m_entities[EntityId::BIRD] = std::make_unique<Bird>();

    const Vec2f pipe_1_pos { m_width + m_settings.PIPE_SPACING, 0 };
    const Vec2f pipe_2_pos { m_width + m_settings.PIPE_SPACING * 2, 0 };
    const Vec2f pipe_3_pos { m_width + m_settings.PIPE_SPACING * 3, 0 };

    m_entities[{ EntityId::PIPE, 0 }] = std::make_unique<Pipe>(pipe_1_pos);
    m_entities[{ EntityId::PIPE, 1 }] = std::make_unique<Pipe>(pipe_2_pos);
    m_entities[{ EntityId::PIPE, 2 }] = std::make_unique<Pipe>(pipe_3_pos);
}

void World::update(const double dt)
{
    static const uint64_t last_tube_nums[] = { 2, 0, 1 };

    for (auto& entity : m_entities) {
        entity->update(dt);
    }

    for (uint64_t i = 0; i < 3; ++i) {

        std::pair<EntityId, uint64_t> curr_tube(EntityId::PIPE, i);

        if (m_entities[curr_tube]->pos().x <= -52) {
            std::pair<EntityId, uint64_t> last_tube(EntityId::PIPE,
                                                    last_tube_nums[i]);
            double next_tube_x = m_entities[last_tube]->pos().x;
            double new_x = next_tube_x + m_settings.PIPE_SPACING;

            m_entities[curr_tube] = std::make_unique<Pipe>(Vec2f { new_x, 0 });
        }
    }
}

Entities const& World::entities() const { return m_entities; }

void World::jump_bird()
{
    Bird* bird = static_cast<Bird*>(m_entities[EntityId::BIRD].get());
    bird->jump();
}

void World::activate_bird()
{
    Bird* bird = static_cast<Bird*>(m_entities[EntityId::BIRD].get());
    bird->activate();
}
