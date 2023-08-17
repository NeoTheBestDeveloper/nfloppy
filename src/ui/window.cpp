#include <cstddef>
#include <format>
#include <iostream>

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <unordered_map>

#include "SDL_events.h"
#include "ui/renderer.hpp"
#include "ui/texture/texture.hpp"
#include "ui/window.hpp"
#include "world/entities/entity.hpp"

using Nfloppy::ui::Window;

Window::Window(const int32_t logical_width, const int32_t logical_height,
               const std::string& title)
    : m_title(title)
    , m_logical_width(logical_width)
    , m_logical_height(logical_height)
{
}

Window::~Window()
{
    Renderer::destroy();
    SDL_DestroyWindow(m_window);

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

void Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        m_error = std::format("Failed to init sdl: {}.", SDL_GetError());
        return;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        m_error = "Failed to init sdl_image.";
        return;
    }

    if (TTF_Init() < 0) {
        m_error = "Failed to init sdl_ttf.";
        return;
    }

    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);

    uint32_t window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI
        | SDL_WINDOW_FULLSCREEN_DESKTOP;

    m_window = SDL_CreateWindow(m_title.c_str(), 0, 0, mode.w, mode.h,
                                window_flags);

    if (m_window == nullptr) {
        m_error = "Failed to create sdl window.";
        return;
    }

    Renderer::init(this);

    if (not Renderer::instance().valid()) {
        m_error = Renderer::instance().error();
        return;
    }

    m_is_valid = true;
}

bool Window::valid() const { return m_is_valid; }

const std::string& Window::error() const { return m_error; }

void Window::poll_event() { SDL_PollEvent(&m_event); }
const SDL_Event& Window::event() const { return m_event; }

void Window::render(const Entities& entities)
{
    const Renderer& renderer = Renderer::instance();

    for (const auto& entity : entities) {
        renderer.draw(entity->texture());
    }

    renderer.render();
}
