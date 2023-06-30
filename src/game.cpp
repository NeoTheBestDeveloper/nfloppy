#include <format>
#include <iostream>
#include <memory>

#include "game.hpp"
#include "utils.hpp"

using Nfloppy::Game;
using Nfloppy::Entities::Entity;

Game::Game()
    : m_entities(1)
{
    init_sdl();
    init_entities();
    load_textures();
}

void Game::start()
{
    SDL_Event event;

    double time_accumulator = 0;
    double tick_size = 1. / m_ticks_per_sec;

    int32_t FPS = 0;
    double fps_timer = .0;

    m_last_update = Utils::double_time();

    while (!(event.type == SDL_QUIT) && m_is_running) {
        double dt = Utils::double_time() - m_last_update;
        m_last_update += dt;
        time_accumulator += dt;
        fps_timer += dt;

        while (time_accumulator > tick_size) {
            update(tick_size);
            time_accumulator -= tick_size;
        }

        render();
        FPS += 1;

        if (fps_timer >= 1.0) {
            FPS = 0;
            fps_timer = .0;
        }

        SDL_PollEvent(&event);
    }
}

Game::~Game()
{
    SDL_DestroyTexture(m_background);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Game::init_sdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);

    m_window = SDL_CreateWindow("Nfloppy", 0, 0, mode.w, mode.h,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
                                    | SDL_WINDOW_ALLOW_HIGHDPI);
    m_renderer = SDL_CreateRenderer(m_window, 0, 0);
}

void Game::init_entities()
{
    // Background
    m_entities[0] = std::make_unique<Entity>("assets/background.bmp",
                                             Math::Vec2f { .0, .0 });

    // FpsCounter

    // Bird

    // Tubes
}

void Game::load_textures()
{
    for (size_t i = 0; i < m_entities.size(); ++i) {
        if (not m_entities[i]->load_texture(m_renderer)) {
            std::cout << std::format("Failed to read texture by path '{}'\n",
                                     m_entities[i]->texture_path());
            m_is_running = false;
            return;
        }
    }
}

void Game::render()
{
    for (size_t i = 0; i < m_entities.size(); ++i) {
        m_entities[i]->draw(m_renderer);
    }

    SDL_RenderPresent(m_renderer);
}

void Game::update(double dt) { }
