#include <format>
#include <iostream>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL_image.h>

#include "entities/entities.hpp"
#include "game.hpp"
#include "utils.hpp"

using Nfloppy::Game;
using Nfloppy::Entities::Background;

Game::Game()
    : m_entities(1)
{
    if (not init_sdl()) {
        m_is_running = false;
        return;
    }

    init_entities();

    if (not load_textures()) {
        m_is_running = false;
        return;
    }
}

void Game::start()
{
    SDL_Event event;

    double time_accumulator = 0;
    double tick_size = 1. / m_ticks_per_sec;

    m_last_update = Utils::double_time();

    while (!(event.type == SDL_QUIT) && m_is_running) {
        double dt = Utils::double_time() - m_last_update;
        m_last_update += dt;
        time_accumulator += dt;

        while (time_accumulator > tick_size) {
            update(tick_size);
            time_accumulator -= tick_size;
        }

        render();

        SDL_PollEvent(&event);
    }
}

Game::~Game()
{
    free_textures();
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    IMG_Quit();
}

// TODO: Set logical size for renderer.
bool Game::init_sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        std::cout << "[ERROR] Failed to init sdl: " << SDL_GetError() << ".\n";
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        std::cout << "[ERROR] Failed to init sdl_image.\n";
        return false;
    }

    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);

    m_window = SDL_CreateWindow("Nfloppy", 0, 0, mode.w, mode.h,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
                                    | SDL_WINDOW_ALLOW_HIGHDPI);
    if (m_window == nullptr) {
        std::cout << "[ERROR] Failed to create sdl window.\n";
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        std::cout << "[ERROR] Failed to create sdl renderer.\n";
        return false;
    }

    std::cout << "[LOG] Sdl init is complete.\n";
    return true;
}

// TODO: absolute pathes for assets with variables.
void Game::init_entities()
{
    // Background
    m_entities[0] = std::make_unique<Background>(Math::Vec2f { .0, .0 },
                                                 Math::Vec2f { .0, .0 });

    // FpsCounter
    // m_entities[1] = std::make_unique<Entities::FpsCounter>(
    //     Math::Vec2f { .0, .0 }, Math::Vec2f { .0, .0 });

    // Bird

    // Tubes

    std::cout << "[LOG] Entities init is complete.\n";
}

bool Game::load_textures()
{
    for (size_t i = 0; i < m_entities.size(); ++i) {
        if (not m_entities[i]->load_texture(m_renderer)) {
            return false;
        }
    }

    std::cout << "[LOG] Textures loading is complete.\n";
    return true;
}

void Game::render()
{
    for (size_t i = 0; i < m_entities.size(); ++i) {
        m_entities[i]->draw(m_renderer);
    }

    SDL_RenderPresent(m_renderer);
}

void Game::update(double dt)
{
    for (size_t i = 0; i < m_entities.size(); ++i) {
        m_entities[i]->update(dt);
    }
}

void Game::free_textures()
{
    for (size_t i = 0; i < m_entities.size(); ++i) {
        m_entities[i]->free_texture();
    }
}
