#include <SDL_events.h>
#include <format>

#include <SDL_image.h>
#include <SDL_ttf.h>

#include "common/logger.hpp"
#include "ui/renderer.hpp"
#include "ui/window.hpp"

using Nfloppy::Common::Logger;
using Nfloppy::ui::Window;

Window::Window(const int32_t logical_width, const int32_t logical_height,
               const std::string& title)
{
    Logger& logger = Logger::instance();

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        logger.panic(std::format("Failed to init sdl: {}.", SDL_GetError()));
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        logger.panic(
            std::format("Failed to init sdl_img: {}.", IMG_GetError()));
    }

    if (TTF_Init() < 0) {
        logger.panic(
            std::format("Failed to init sdl_ttf: {}.", TTF_GetError()));
    }

    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);

    uint32_t window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI
        | SDL_WINDOW_FULLSCREEN_DESKTOP;

    m_window
        = SDL_CreateWindow(title.c_str(), 0, 0, mode.w, mode.h, window_flags);

    if (m_window == nullptr) {
        logger.panic("Failed to create sdl window.");
    }

    poll_event();

    Renderer::init(m_window, logical_width, logical_height);

    logger.info("Window creation complete.");
}

Window::~Window()
{
    Renderer::destroy();
    SDL_DestroyWindow(m_window);

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

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
