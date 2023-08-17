#pragma once

#include <SDL2/SDL.h>

#include "ui/window.hpp"

using Nfloppy::ui::Window;

// TODO: Rewrite all to modules.

namespace Nfloppy {

class Game final {

public:
    Game();

    Game(Game const&) = delete;
    Game operator=(Game const&) = delete;

    void start();

private:
    Window m_window;

    double m_last_update = 0.0;
    int32_t m_ticks_per_sec = 100;

    bool m_is_running = true;

    void input();
    void handle_keyboard();
};

} // namespace Nfloppy
