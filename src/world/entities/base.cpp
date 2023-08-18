#include "world/entities/base.hpp"

using Nfloppy::World::Entities::Base;

Base::Base(EntityId id, Math::Vec2f const& pos, Math::Vec2f const& size)
    : Entity(id, pos, size)
{
    m_velocity = { -40, 0 };
}

void Base::update(double dt)
{
    Math::Vec2f m_pos_copy = m_pos;
    Math::Vec2f m_velocity_copy = m_velocity;

    m_pos = m_pos_copy + m_velocity_copy * dt;

    if (m_pos.x <= -26) {
        m_pos.x = 0;
    }

    m_texture.update_pos(m_pos);
}
