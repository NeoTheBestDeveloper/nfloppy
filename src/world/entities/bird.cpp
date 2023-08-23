#include <cmath>

#include "math/vec2.hpp"
#include "world/entities/bird.hpp"
#include "world/world_settings.hpp"

using Nfloppy::Math::Vec2f;
using Nfloppy::World::Entities::Bird;

Bird::Bird(EntityId id, Vec2f const& pos, Vec2f const& size)
    : Entity(id, pos, size)
    , m_texture(id, pos, size, 0.13)
    , m_base_y(pos.y)

{
    m_velocity.y = 23;
}

Texture const& Bird::texture() const { return m_texture; }

void Bird::update(double dt)
{
    m_pos = m_pos + m_velocity * dt;

    if (abs(m_base_y - m_pos.y) >= 5) {
        m_velocity.y = -m_velocity.y;
    }

    m_texture.update_pos(m_pos);
    m_texture.animate(dt);
}
