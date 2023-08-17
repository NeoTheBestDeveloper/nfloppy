#include "world/entities/bird.hpp"

using Nfloppy::World::Entities::Bird;

Bird::Bird(EntityId id, Math::Vec2f const& pos, Math::Vec2f const& size)
    : Entity(id, pos, size)
{
    m_velocity = { -40, 0 };
}

void Bird::update(double dt) { }
