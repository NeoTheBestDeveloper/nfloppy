#include "ui/renderer.hpp"
#include "common/logger.hpp"

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

void Renderer::render() const { SDL_RenderPresent(m_renderer); }
