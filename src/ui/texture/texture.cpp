#include <format>

#include "SDL_render.h"
#include "SDL_ttf.h"
#include <SDL_image.h>

#include "ui/renderer.hpp"
#include "ui/texture/texture.hpp"
#include "ui/texture/texture_pathes.hpp"

using Nfloppy::ui::Texture::Texture;

Texture::Texture(EntityId id, Vec2f size, Vec2f pos)
    : m_box({
        static_cast<int>(pos.x),
        static_cast<int>(pos.y),
        static_cast<int>(size.x),
        static_cast<int>(size.y),
    })
    , m_id(id)
{
}

void Texture::load()
{
    const Renderer& renderer = Renderer::instance();

    const TexturePathes& pathes = TexturePathes::instance();
    SDL_Surface* texture_surf = IMG_Load(pathes[m_id].c_str());

    if (texture_surf == nullptr) {
        m_error = std::format("Failed to load '{}' texture. Cause: ''",
                              pathes[m_id].c_str(), IMG_GetError());
        return;
    }

    m_texture = renderer.create_texture(texture_surf);

    SDL_FreeSurface(texture_surf);

    m_is_valid = true;
}

bool Texture::valid() const { return m_is_valid; }

const std::string& Texture::error() const { return m_error; }
Texture::~Texture() { SDL_DestroyTexture(m_texture); }

void Texture::update_pos(Vec2f new_pos)
{
    m_box.x = static_cast<int>(new_pos.x);
    m_box.y = static_cast<int>(new_pos.y);
}

void Texture::update_size(Vec2f new_size)
{
    m_box.w = static_cast<int>(new_size.x);
    m_box.h = static_cast<int>(new_size.y);
}

SDL_Texture* Texture::sdl_texture() const { return m_texture; }

const SDL_Rect* Texture::sdl_rect() const { return &m_box; }
