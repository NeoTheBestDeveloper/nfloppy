#include "ui/texture/texture.hpp"

using Nfloppy::ui::Texture::Texture;

Texture::Texture(EntityId, Vec2f const& pos, Vec2f const& size)
    : m_box({
        static_cast<int>(pos.x),
        static_cast<int>(pos.y),
        static_cast<int>(size.x),
        static_cast<int>(size.y),
    })
{
}

void Texture::update_pos(Vec2f const& new_pos)
{
    m_box.x = static_cast<int>(new_pos.x);
    m_box.y = static_cast<int>(new_pos.y);
}

SDL_Texture* Texture::sdl_texture() const { return m_texture; }

const SDL_Rect* Texture::sdl_rect() const { return &m_box; }
