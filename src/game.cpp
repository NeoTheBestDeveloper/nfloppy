#include <SDL.h>

#include "game.hpp"

using Nfloppy::Game;

Game::Game() { sdl_init(); }

Game::~Game()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}

void Game::start()
{
    SDL_Event event;

    while (event.type != SDL_QUIT) {
        step();
        render();

        SDL_Delay(5);
        SDL_PollEvent(&event);
    }
}

void Game::sdl_init()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);

    m_window = SDL_CreateWindow("Nfloppy", 0, 0, mode.w, mode.h,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
                                    | SDL_WINDOW_ALLOW_HIGHDPI);
    m_renderer = SDL_CreateRenderer(m_window, 0, 0);

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
}

void Game::step() { }

void Game::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);

    // Some drawable stuff.

    SDL_RenderPresent(m_renderer);
}
