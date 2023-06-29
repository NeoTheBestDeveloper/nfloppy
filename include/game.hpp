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

    bool m_is_end = false;

    void sdl_init();
    void load_textures();

    void draw_backgroud();

    void render();

    void step();
};

} // namespace Nfloppy
