#include <iostream>
#include <memory>

#include "ui/renderer.hpp"

using Nfloppy::ui::Renderer;

Renderer::Renderer(const Window* win)
{
    m_renderer
        = SDL_CreateRenderer(win->m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_renderer == nullptr) {
        m_error = "Failed to create sdl renderer.";
        return;
    }

    SDL_RenderSetLogicalSize(m_renderer, win->m_logical_width,
                             win->m_logical_height);

    m_is_valid = true;
}

SDL_Texture* Renderer::create_texture(SDL_Surface* surf) const
{
    return SDL_CreateTextureFromSurface(m_renderer, surf);
}

bool Renderer::valid() const { return m_is_valid; }
const std::string& Renderer::error() const { return m_error; }

void Renderer::draw(const Texture::Texture& texture) const
{
    SDL_RenderCopy(m_renderer, texture.sdl_texture(), nullptr,
                   texture.sdl_rect());
}

void Renderer::render() const { SDL_RenderPresent(m_renderer); }
