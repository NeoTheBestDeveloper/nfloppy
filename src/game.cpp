#include <format>
#include <iostream>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "entities/entities.hpp"
#include "font.hpp"
#include "game.hpp"
#include "utils.hpp"

using Nfloppy::Game;
using Nfloppy::Entities::Background;
using Nfloppy::Entities::FpsCounter;

// TODO: add Logger.
// TODO: Add chain pattern.
Game::Game()
    : m_entities(2)
    , m_event({ 0 })
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
    double time_accumulator = 0;
    double tick_size = 1. / m_ticks_per_sec;

    m_last_update = Utils::double_time();

    while (!(m_event.type == SDL_QUIT) && m_is_running) {
        double dt = Utils::double_time() - m_last_update;
        m_last_update += dt;
        time_accumulator += dt;

        SDL_PollEvent(&m_event);
        input();

        while (time_accumulator > tick_size) {
            update(tick_size);
            time_accumulator -= tick_size;
        }

        render();
    }
}

Game::~Game()
{
    free_textures();

    TTF_CloseFont(Nfloppy::SDL_FONT);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

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

    if (TTF_Init() < 0) {
        std::cout << "[ERROR] Failed to init sdl_ttf.\n";
        return false;
    }

    Nfloppy::SDL_FONT = TTF_OpenFont("./assets/font.ttf", 24);

    if (Nfloppy::SDL_FONT == nullptr) {
        std::cout << "[ERROR] Failed to load font: " << SDL_GetError()
                  << ".\n";
        return false;
    }

    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);

    m_window = SDL_CreateWindow("Nfloppy", 0, 0, mode.w, mode.h,
                                SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI
                                    | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (m_window == nullptr) {
        std::cout << "[ERROR] Failed to create sdl window.\n";
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        std::cout << "[ERROR] Failed to create sdl renderer.\n";
        return false;
    }

    SDL_RenderSetLogicalSize(m_renderer, Nfloppy::LOGICAL_WINDOW_WIDTH,
                             Nfloppy::LOGICAL_WINDOW_HEIGHT);

    std::cout << "[LOG] Sdl init is complete.\n";

    return true;
}

// TODO: absolute pathes for assets with variables.
void Game::init_entities()
{
    // Background
    m_entities[0] = std::make_unique<Background>(Math::Vec2f { .0, .0 },
                                                 Game::BACKGROUND_SIZE);

    // FpsCounter
    m_entities[1] = std::make_unique<FpsCounter>(Math::Vec2f { 20, .5 },
                                                 Math::Vec2f { 160, 90 });

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
        m_entities[i]->update(dt, m_renderer);
    }
}

void Game::free_textures()
{
    for (size_t i = 0; i < m_entities.size(); ++i) {
        m_entities[i]->free_texture();
    }
}

void Game::handle_keyboard()
{
    if (m_event.key.keysym.scancode == SDL_SCANCODE_F) {
        m_entities[1]->toggle_hide();
    }
}

void Game::input()
{
    if (m_event.type == SDL_KEYDOWN) {
        handle_keyboard();
    }
}
