#pragma once

#include <memory>
#include <vector>

#include <SDL.h>

#include <entities/entities.hpp>

namespace Nfloppy {

class Game final {

public:
    Game();
    ~Game();

    Game(Game const&) = delete;
    Game operator=(Game const&) = delete;

    void start();

private:
    // ID:
    // 0 - Background
    // 1 - FpsCounter
    // 2 - Bird
    // 3:N - Tubes
    std::vector<std::unique_ptr<Entities::Entity>> m_entities;

    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    SDL_Texture* m_background = nullptr;

    double m_last_update = 0.0;
    int32_t m_ticks_per_sec = 100;

    bool m_is_running = true;

    void init_sdl();
    void init_entities();
    void load_textures();

    void render();
    void update(double dt);
};

} // namespace Nfloppy
