#include "world/entities/entity.hpp"
#include "ui/texture/texture.hpp"

using Nfloppy::World::Entities::Entity;

Entity::Entity(EntityId id, Vec2f const& pos, Vec2f const& size)
    : m_pos(pos)
    , m_size(size)
    , m_texture(id, size, pos)
{
    m_texture.load();
}

const Texture& Entity::texture() const { return m_texture; }

void Entity::update(double dt) { }
const Vec2f& Entity::size() const { return m_size; }
const Vec2f& Entity::pos() const { return m_pos; }
