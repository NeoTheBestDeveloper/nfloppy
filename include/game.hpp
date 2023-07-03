#pragma once

#include <memory>
#include <vector>

#include <SDL2/SDL.h>

#include "defaults.hpp"
#include "entities/entities.hpp"

namespace Nfloppy {

class Game final {

public:
    Game();
    ~Game();

    Game(Game const&) = delete;
    Game operator=(Game const&) = delete;

    void start();

private:
    static inline const Math::Vec2f BACKGROUND_SIZE = {
        Nfloppy::LOGICAL_WINDOW_WIDTH,
        Nfloppy::LOGICAL_WINDOW_HEIGHT,
    };

    // TODO: fix these wierd ids.
    // ID:
    // 0 - Background
    // 1 - FpsCounter
    // 2 - Bird
    // 3:N - Tubes

    // TODO: Use arena allocator instead of unique_ptr.
    std::vector<std::unique_ptr<Entities::Entity>> m_entities;

    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    SDL_Event m_event;

    double m_last_update = 0.0;
    int32_t m_ticks_per_sec = 100;

    bool m_is_running = true;

    bool init_sdl();
    void init_entities();
    bool load_textures();

    void input();
    void handle_keyboard();

    void render();
    void update(double dt);

    void free_textures();
};

} // namespace Nfloppy
