#include "world/world.hpp"
#include "world/entities/bird.hpp"

using Nfloppy::World::World;
using Nfloppy::World::Entities::Background;
using Nfloppy::World::Entities::Base;
using Nfloppy::World::Entities::Bird;
using Nfloppy::World::Entities::EntityId;

World::World(const int32_t width, const int32_t height)
    : m_entities(3)
    , m_settings(width, height)

{
    // TODO: fabric for entity.
    m_entities[EntityId::BACKGROUND] = std::make_unique<Background>(
        EntityId::BACKGROUND, m_settings.BACKGROUND_POS,
        m_settings.BACKGROUND_SIZE);

    m_entities[EntityId::BASE] = std::make_unique<Base>(
        EntityId::BASE, m_settings.BASE_POS, m_settings.BASE_SIZE);

    m_entities[EntityId::BIRD] = std::make_unique<Bird>(
        EntityId::BIRD, m_settings.BIRD_POS, m_settings.BIRD_SIZE);
}

void World::update(const double dt)
{
    for (const auto& entity : m_entities) {
        entity->update(dt);
    }
}
