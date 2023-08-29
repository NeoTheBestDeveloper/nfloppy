#include "ui/texture/texture.hpp"
#include "ui/renderer.hpp"

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

Texture::Texture(Vec2f const& pos, Vec2f const& size)
    : m_box({
        static_cast<int>(pos.x),
        static_cast<int>(pos.y),
        static_cast<int>(size.x),
        static_cast<int>(size.y),
    })
{
    Renderer const& render = Renderer::instance();
    m_texture = render.create_texture(size);
}

void Texture::update_pos(Vec2f const& new_pos)
{
    m_box.x = static_cast<int>(new_pos.x);
    m_box.y = static_cast<int>(new_pos.y);
}

SDL_Texture* Texture::sdl_texture() const { return m_texture; }

const SDL_Rect* Texture::sdl_rect() const { return &m_box; }

void Texture::set_sdl_texture(SDL_Texture* new_texture)
{
    m_texture = new_texture;
}
