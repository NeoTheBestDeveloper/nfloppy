#include "world/entities/base.hpp"
#include "world/world_settings.hpp"

using Nfloppy::World::Entities::Base;

Base::Base()
    : Entity(EntityId::BASE, WorldSettings().BASE_POS,
             WorldSettings().BASE_SIZE)
    , m_texture(EntityId::BASE, WorldSettings().BASE_POS,
                WorldSettings().BASE_SIZE)
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
