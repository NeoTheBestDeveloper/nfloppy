#include <cmath>

#include "world/entities/bird.hpp"
#include "world/world_settings.hpp"

using Nfloppy::World::Entities::Bird;

Bird::Bird()
    : Entity(EntityId::BIRD, WorldSettings().BIRD_POS,
             WorldSettings().BIRD_SIZE)
    , m_texture(EntityId::BIRD, WorldSettings().BIRD_POS,
                WorldSettings().BIRD_SIZE, 0.13)
    , m_base_y(WorldSettings().BIRD_POS.y)

{
    m_velocity.y = 23;
}

Texture const& Bird::texture() const { return m_texture; }

void Bird::update(double dt)
{
    m_velocity = m_velocity + m_acceleration * dt;
    m_pos = m_pos + m_velocity * dt;

    if (abs(m_base_y - m_pos.y) >= 5 and not m_active) {
        m_velocity.y = -m_velocity.y;
    }

    m_texture.update_pos(m_pos);
    m_texture.animate(dt);
}

void Bird::activate()
{
    m_active = true;
    m_acceleration.y = 600;
}

void Bird::jump() { m_velocity.y = -210; }
