#include "world/entities/background.hpp"
#include "world/world_settings.hpp"

using Nfloppy::World::Entities::Background;

Background::Background()
    : Entity(EntityId::BACKGROUND, WorldSettings().BACKGROUND_POS,
             WorldSettings().BACKGROUND_SIZE)
    , m_texture(EntityId::BACKGROUND, WorldSettings().BACKGROUND_POS,
                WorldSettings().BACKGROUND_SIZE)
{
}

Texture const& Background::texture() const { return m_texture; }

void Background::update(double) { }
