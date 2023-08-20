#include "world/world.hpp"

using Nfloppy::World::World;
using Nfloppy::World::Entities::Background;
using Nfloppy::World::Entities::Base;
using Nfloppy::World::Entities::Bird;
using Nfloppy::World::Entities::Entities;
using Nfloppy::World::Entities::EntityId;

World::World(const int32_t width, const int32_t height)
    : m_entities(3)
    , m_settings(width, height)

{
    m_entities[EntityId::BACKGROUND] = make_background();
    m_entities[EntityId::BASE] = make_base();
    m_entities[EntityId::BIRD] = make_bird();
}

void World::update(const double dt)
{
    for (auto& entity : m_entities) {
        entity->update(dt);
    }
}

const Entities& World::entities() const { return m_entities; }

EntityPtr World::make_background() const
{
    return std::make_unique<Background>(EntityId::BACKGROUND,
                                        m_settings.BACKGROUND_POS,
                                        m_settings.BACKGROUND_SIZE);
}

EntityPtr World::make_base() const
{
    return std::make_unique<Base>(EntityId::BASE, m_settings.BASE_POS,
                                  m_settings.BASE_SIZE);
}

EntityPtr World::make_bird() const
{
    return std::make_unique<Bird>(EntityId::BIRD, m_settings.BIRD_POS,
                                  m_settings.BIRD_SIZE);
}
