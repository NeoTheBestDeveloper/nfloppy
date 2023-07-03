#include <iostream>

#include <SDL_image.h>

#include "entities/base.hpp"

using Nfloppy::Entities::Base;

Base::Base(Math::Vec2f const& pos, Math::Vec2f const& size)
    : Entity(pos, size)
{
    m_velocity = { -40, 0 };
}

bool Base::load_texture(SDL_Renderer* renderer)
{
    SDL_Surface* texture_surf = IMG_Load(Base::TEXTURE_PATH.c_str());
    if (texture_surf == nullptr) {
        std::cout << "[ERROR] Failed to load base texture: " << IMG_GetError()
                  << ".\n";
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(renderer, texture_surf);
    SDL_FreeSurface(texture_surf);

    return true;
}

// FIXME: fix vector overload ops.
void Base::update(double dt, SDL_Renderer*)
{
    Math::Vec2f m_pos_copy = m_pos;
    Math::Vec2f m_velocity_copy = m_velocity;

    m_pos = m_pos_copy + m_velocity_copy * dt;

    if (m_pos.x <= -48) {
        m_pos.x = 0;
    }

    m_texture_size.x = static_cast<int32_t>(m_pos.x);
    m_texture_size.y = static_cast<int32_t>(m_pos.y);
}
