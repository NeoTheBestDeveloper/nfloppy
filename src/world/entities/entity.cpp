#include "world/entities/entity.hpp"
#include "ui/texture/texture.hpp"

using Nfloppy::World::Entities::Entity;

Entity::Entity(EntityId, Vec2f const& pos, Vec2f const& size)
    : m_pos(pos)
    , m_size(size)
{
}

Vec2f const& Entity::size() const { return m_size; }

Vec2f const& Entity::pos() const { return m_pos; }

void Entity::set_velocity(Vec2f const& new_velocity)
{
    m_velocity = new_velocity;
}

void Entity::set_acceleration(Vec2f const& new_acceleration)
{
    m_acceleration = new_acceleration;
}
