#include "entities/entity.hpp"

using Nfloppy::Entities::Entity;

Entity::Entity(Math::Vec2f const& pos, Math::Vec2f const& size)
    : m_pos(pos)
    , m_size(size)
{
}

// TODO: Set postion for rendering.
void Entity::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, m_texture, nullptr, nullptr);
}

void Entity::update(double dt) { }

void Entity::set_velocity(Math::Vec2f const& v) { m_velocity = v; }

void Entity::set_acceleration(Math::Vec2f const& a) { m_acceleration = a; }
void Entity::free_texture() { SDL_DestroyTexture(m_texture); }
