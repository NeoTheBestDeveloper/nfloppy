#include "world/entities/base.hpp"

using Nfloppy::World::Entities::Base;

Base::Base(EntityId id, Vec2f const& pos, Vec2f const& size)
    : Entity(id, pos, size)
    , m_texture(id, pos, size)
{
    m_velocity = { -80, 0 };
}

Texture const& Base::texture() const { return m_texture; }

void Base::update(double dt)
{
    m_pos = m_pos + m_velocity * dt;

    if (m_pos.x <= -26) {
        m_pos.x = 0;
    }

    m_texture.update_pos(m_pos);
}
