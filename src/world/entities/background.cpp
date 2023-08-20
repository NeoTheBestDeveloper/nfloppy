#include "world/entities/background.hpp"

using Nfloppy::World::Entities::Background;

Background::Background(EntityId id, Vec2f const& pos, Vec2f const& size)
    : Entity(id, pos, size)
{
}
