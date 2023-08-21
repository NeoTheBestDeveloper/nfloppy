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
