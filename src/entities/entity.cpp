#include "entities/entity.hpp"

using Nfloppy::Entities::Entity;

Entity::Entity(Math::Vec2f const& pos, Math::Vec2f const& size, bool is_hidden)
    : m_pos(pos)
    , m_size(size)
    , m_is_hidden(is_hidden)
{
    m_texture_size = {
        .x = static_cast<int32_t>(m_pos.x),
        .y = static_cast<int32_t>(m_pos.y),
        .w = static_cast<int32_t>(m_size.x),
        .h = static_cast<int32_t>(m_size.y),
    };
}

void Entity::draw(SDL_Renderer* renderer)
{
    if (not m_is_hidden) {
        SDL_RenderCopy(renderer, m_texture, nullptr, &m_texture_size);
    }
}

void Entity::update(double dt, SDL_Renderer*)
{
    m_texture_size.x = static_cast<int32_t>(m_pos.x);
    m_texture_size.y = static_cast<int32_t>(m_pos.y);
}

void Entity::set_velocity(Math::Vec2f const& v) { m_velocity = v; }
void Entity::set_acceleration(Math::Vec2f const& a) { m_acceleration = a; }

void Entity::free_texture() { SDL_DestroyTexture(m_texture); }

bool Entity::is_hidden() const { return m_is_hidden; }
void Entity::hide() { m_is_hidden = true; }
void Entity::show() { m_is_hidden = false; }
void Entity::toggle_hide() { m_is_hidden = not m_is_hidden; }
