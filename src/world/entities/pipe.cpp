#include "world/entities/pipe.hpp"
#include "world/entities/entity.hpp"

using Nfloppy::World::Entities::Pipe;

Pipe::Pipe(EntityId id, Vec2f const& pos, Vec2f const& size,
           PipeDirection direction)
    : Entity(id, pos, size)
    , m_texture(id, pos, size)
{
    if (direction == PipeDirection::DOWN) {
        m_texture.rotate(180.0);
    }

    m_velocity = { -80, 0 };
}

void Pipe::update(double dt)
{
    m_pos = m_pos + m_velocity * dt;
    m_texture.update_pos(m_pos);
}

Texture const& Pipe::texture() const { return m_texture; }
