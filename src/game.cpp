#include "game.hpp"
#include "utils.hpp"

using Nfloppy::Game;

Game::Game()
{
    sdl_init();
    load_textures();
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

void Game::update(double dt) { }
