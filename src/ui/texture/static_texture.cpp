#include <format>

#include <SDL.h>
#include <SDL_image.h>

#include "SDL_render.h"
#include "common/logger.hpp"
#include "ui/renderer.hpp"
#include "ui/texture/static_texture.hpp"
#include "ui/texture/texture_pathes.hpp"

using Nfloppy::Common::Logger;
using Nfloppy::ui::Texture::StaticTexture;

StaticTexture::StaticTexture(EntityId id, Vec2f const& pos, Vec2f const& size)
    : Texture(id, pos, size)
{
    load(id);
}

StaticTexture::~StaticTexture() { SDL_DestroyTexture(m_texture); }

void StaticTexture::load(EntityId id)
{
    Logger& logger = Logger::instance();
    const Renderer& renderer = Renderer::instance();

    const TexturePathes& pathes = TexturePathes::instance();
    const char* path = pathes[id][0].c_str();

    SDL_Surface* texture_surf = IMG_Load(path);

    if (texture_surf == nullptr) {
        logger.panic(std::format("Failed to load '{}' texture. Cause: ''",
                                 path, IMG_GetError()));
    }

    m_texture = renderer.create_texture(texture_surf);

    SDL_FreeSurface(texture_surf);
}

void StaticTexture::rotate(double angle)
{
    Renderer const& renderer = Renderer::instance();

    SDL_Texture* new_texture = renderer.rotate_texture(m_texture, angle);
    SDL_DestroyTexture(m_texture);

    m_texture = new_texture;
}
