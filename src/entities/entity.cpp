#include "entities/entity.hpp"

using Nfloppy::Entities::Entity;

Entity::Entity(std::string const& texture_path, Math::Vec2f const& pos)
    : m_pos(pos)
    , m_texture(texture_path)
{
}

// TODO: Set postion for rendering.
void Entity::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, m_texture.sdl_texture(), nullptr, nullptr);
}

bool Entity::load_texture(SDL_Renderer* renderer)
{
    return m_texture.load(renderer);
}

char const* Entity::texture_path() const { return m_texture.path(); }

void Entity::update(double dt) { }

void Entity::set_velocity(Math::Vec2f const& v) { m_velocity = v; }

void Entity::set_acceleration(Math::Vec2f const& a) { m_acceleration = a; }
