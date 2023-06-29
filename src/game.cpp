#include "game.hpp"

using Nfloppy::Game;

Game::Game()
{
    sdl_init();
    load_textures();
}

void Game::start()
{
    SDL_Event event;

    while (!(event.type == SDL_QUIT)) {
        render();
        step();

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

void Game::sdl_init()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);

    m_window = SDL_CreateWindow("Nfloppy", 0, 0, mode.w, mode.h,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
                                    | SDL_WINDOW_ALLOW_HIGHDPI);
    m_renderer = SDL_CreateRenderer(m_window, 0, 0);
}

void Game::load_textures()
{
    SDL_Surface* background_surf = SDL_LoadBMP("assets/background.bmp");
    m_background = SDL_CreateTextureFromSurface(m_renderer, background_surf);
    SDL_FreeSurface(background_surf);
}

void Game::render()
{
    SDL_RenderCopy(m_renderer, m_background, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
}

void Game::step() { }
