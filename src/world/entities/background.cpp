#include "world/entities/background.hpp"

using Nfloppy::World::Entities::Background;

Background::Background(EntityId id, Math::Vec2f const& pos,
                       Math::Vec2f const& size)
    : Entity(id, pos, size)
{
}
