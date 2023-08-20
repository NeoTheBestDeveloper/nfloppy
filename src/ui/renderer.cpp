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

    m_renderer = SDL_CreateRenderer(s_win, -1, SDL_RENDERER_ACCELERATED);

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

void Renderer::draw(const std::string& msg, Vec2f pos, Vec2f size) const
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

void Renderer::render() const { SDL_RenderPresent(m_renderer); }
