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
    double m_elapsed;
    int32_t m_ticks_per_sec = 80;
    bool m_is_running = true;

    double elapsed() const;

    void input();
    void handle_keyboard();
};

} // namespace Nfloppy
