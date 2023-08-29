#include "world/entities/pipe.hpp"
#include "common/range_random.hpp"
#include "world/entities/entity.hpp"
#include "world/world_settings.hpp"

using Nfloppy::Common::RangeRandom;
using Nfloppy::World::Entities::Pipe;

Pipe::Pipe(Vec2f const& pos)
    : Entity(EntityId::PIPE, pos, WorldSettings().PIPE_SIZE)
    , m_texture(pos, WorldSettings().PIPE_SIZE)
{
    m_velocity = { -80, 0 };

    RangeRandom rand(50, 300);
    double bottom_pipe_height = static_cast<double>(rand.generate());

    double bottom_y = get_bottom_pipe_y(bottom_pipe_height);
    const StaticTexture bottom_pipe(EntityId::PIPE, Vec2f { 0, bottom_y },
                                    Vec2f { 52, 320 });

    double upper_y = get_upper_pipe_y(bottom_pipe_height);
    StaticTexture upper_pipe(EntityId::PIPE, Vec2f { 0, upper_y },
                             Vec2f { 52, 320 });
    upper_pipe.rotate(180.0);

    m_texture.insert_texture(bottom_pipe);
    m_texture.insert_texture(upper_pipe);
}

void Pipe::update(double dt)
{
    m_pos = m_pos + m_velocity * dt;
    m_texture.update_pos(m_pos);
}

Texture const& Pipe::texture() const { return m_texture; }

double Pipe::get_bottom_pipe_y(double bottom_pipe_height) const
{
    WorldSettings settings;
    return settings.BACKGROUND_SIZE.y - settings.BASE_SIZE.y
        - bottom_pipe_height;
}

double Pipe::get_upper_pipe_y(double bottom_pipe_height) const
{
    WorldSettings settings;
    return -(320
             - (settings.BACKGROUND_SIZE.y - settings.BASE_SIZE.y
                - settings.PIPE_HOLE - bottom_pipe_height));
}
