#include "ui/renderer.hpp"
#include "SDL_render.h"
#include "SDL_ttf.h"
#include "common/logger.hpp"
#include <format>

using Nfloppy::Common::Logger;
using Nfloppy::ui::Renderer;

Renderer::Renderer()
{
    Logger& logger = Logger::instance();

    m_renderer = SDL_CreateRenderer(
        s_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    if (m_renderer == nullptr) {
        logger.panic("Failed to create sdl renderer.");
    }

    SDL_RenderSetLogicalSize(m_renderer, s_logical_width, s_logical_height);

    s_font = TTF_OpenFont("./assets/font.ttf", 24);

    if (s_font == nullptr) {
        logger.panic(std::format(
            "Failed to create sdl renderer (cannot init font). Cause: \"{}\"",
            TTF_GetError()));
    }

    logger.info("Renderer creation complete.");
}

SDL_Texture* Renderer::create_texture(SDL_Surface* surf) const
{
    return SDL_CreateTextureFromSurface(m_renderer, surf);
}

void Renderer::draw(const Texture::Texture& texture) const
{
    SDL_RenderCopy(m_renderer, texture.sdl_texture(), nullptr,
                   texture.sdl_rect());
}

void Renderer::draw(std::string const& msg, Vec2f const& pos,
                    Vec2f const& size) const
{
    SDL_Surface* msg_surface
        = TTF_RenderText_Solid(s_font, msg.c_str(), m_color);
    SDL_Texture* msg_texture
        = SDL_CreateTextureFromSurface(m_renderer, msg_surface);

    SDL_Rect msg_rect = {
        static_cast<int>(pos.x),
        static_cast<int>(pos.y),
        static_cast<int>(size.x),
        static_cast<int>(size.y),
    };

    SDL_RenderCopy(m_renderer, msg_texture, nullptr, &msg_rect);

    SDL_FreeSurface(msg_surface);
    SDL_DestroyTexture(msg_texture);
}

void Renderer::render() const
{
    SDL_RenderPresent(m_renderer);
    SDL_RenderClear(m_renderer);
}

SDL_Texture* Renderer::rotate_texture(SDL_Texture* texture, double angle) const
{
    int32_t width, heigth;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &heigth);

    SDL_Texture* result
        = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA4444,
                            SDL_TEXTUREACCESS_TARGET, width, heigth);
    SDL_SetTextureBlendMode(result, SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(m_renderer, result);

    SDL_RenderCopyEx(m_renderer, texture, nullptr, nullptr, angle, nullptr,
                     SDL_FLIP_NONE);
    SDL_SetRenderTarget(m_renderer, nullptr);

    return result;
}

void Renderer::copy_texture(class Texture const& src, class Texture& dst) const
{
    SDL_SetRenderTarget(m_renderer, dst.sdl_texture());
    SDL_RenderCopy(m_renderer, src.sdl_texture(), nullptr, src.sdl_rect());

    SDL_SetRenderTarget(m_renderer, nullptr);
}

// Create transparant void texture.
SDL_Texture* Renderer::create_texture(Vec2f const& size) const
{
    SDL_Texture* texture = SDL_CreateTexture(
        m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
        static_cast<int>(size.x), static_cast<int>(size.y));
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    return texture;
}
