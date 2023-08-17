#include <format>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "game.hpp"
#include "world/world.hpp"

using Nfloppy::Game;

// TODO: add Logger.
// TODO: Add chain pattern.
Game::Game()
    : m_window(288, 512, "Nfloppy")
{
}

void Game::start()
{
    m_window.init();

    if (not m_window.valid()) {
        std::cout << std::format("[ERROR] {}\n", m_window.error());
        return;
    }

    std::cout << std::format("[LOG] Window initialization complete.\n");

    World::World world(288, 512);

    double time_accumulator = 0;
    double tick_size = 1. / m_ticks_per_sec;

    m_last_update = SDL_GetTicks64() / 1000.0;

    while (!(m_window.event().type == SDL_QUIT) && m_is_running) {
        double dt = (SDL_GetTicks64() / 1000.0) - m_last_update;
        m_last_update += dt;
        time_accumulator += dt;

        m_window.poll_event();
        input();

        while (time_accumulator > tick_size) {
            world.update(tick_size);
            time_accumulator -= tick_size;
        }

        m_window.render(world.m_entities);
    }
}

void Game::input() { }

void Game::handle_keyboard() { }
