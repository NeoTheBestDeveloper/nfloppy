#pragma once

#include <SDL.h>

namespace Nfloppy {

class Game {

public:
    Game();
    ~Game();

    Game(Game const&) = delete;
    Game operator=(Game const&) = delete;

    void start();

private:
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    SDL_Texture* m_background = nullptr;

    double m_last_update = 0.0;
    int32_t m_ticks_per_sec = 100;

    bool m_is_running = true;

    void sdl_init();
    void load_textures();

    void draw_backgroud();
    void render();

    void update(double dt);
};

} // namespace Nfloppy
