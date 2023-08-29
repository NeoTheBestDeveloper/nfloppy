#pragma once

#include <SDL2/SDL.h>

#include "ui/window.hpp"
#include "world/world.hpp"

using Nfloppy::ui::Window;
using Nfloppy::World::World;

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
    class World m_world;

    int32_t m_ticks_per_sec = 80;
    bool m_is_running = true;

    double elapsed() const;

    void input();
    void handle_keyboard();
};

} // namespace Nfloppy
