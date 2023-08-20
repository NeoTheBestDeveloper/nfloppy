#include <ctime>

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "game.hpp"
#include "world/world.hpp"

using Nfloppy::Game;

Game::Game()
    : m_window(288, 512, "Nfloppy")
{
}

void Game::start()
{
    World::World world(288, 512);

    double time_accumulator = 0;
    double tick_size = 1. / m_ticks_per_sec;

    double last_update = elapsed();

    while (m_window.event().type != SDL_QUIT && m_is_running) {
        double dt = elapsed() - last_update;
        last_update += dt;
        time_accumulator += dt;

        m_window.poll_event();
        input();

        while (time_accumulator >= tick_size) {
            world.update(tick_size);
            time_accumulator -= tick_size;
        }

        m_window.render(world.entities());
    }
}

double Game::elapsed() const
{
    return static_cast<double>(clock()) / static_cast<double>(CLOCKS_PER_SEC);
}

void Game::input()
{
    if (m_window.event().type == SDL_KEYDOWN) {
        handle_keyboard();
    }
}

void Game::handle_keyboard()
{
    if (m_window.event().key.keysym.sym == SDLK_f) {
        m_window.toggle_fps();
    }
}
