#pragma once

#include <SDL2/SDL.h>

#include "common/timer.hpp"
#include "world/entities/entities.hpp"

using Nfloppy::Common::Timer;
using Nfloppy::World::Entities::Entities;

namespace Nfloppy {

namespace ui {

    class Window final {

    public:
        Window(const int32_t logical_width, const int32_t logical_height,
               const std::string& title);
        ~Window();

        Window(Window const&) = delete;
        Window operator=(Window const&) = delete;

        void toggle_fps();
        void poll_event();

        const SDL_Event& event() const;
        void render(const Entities& entities);

    private:
        SDL_Window* m_window = nullptr;
        SDL_Event m_event = { SDL_FIRSTEVENT };

        Timer m_timer;

        int32_t m_fps_accum = 0;
        int32_t m_fps = 0;
        uint64_t m_fps_updated = 0;

        bool m_fps_shown = false;
    };

}

}
