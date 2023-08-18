#pragma once

#include <SDL.h>

#include "world/entities/entities.hpp"

using Nfloppy::World::Entities::Entities;

namespace Nfloppy {

namespace ui {

    class Window final {

        friend class Renderer;

    public:
        Window(const int32_t logical_width, const int32_t logical_height,
               const std::string& title);
        ~Window();

        void toggle_fps();
        void poll_event();
        const SDL_Event& event() const;
        void render(const Entities& entities);

    private:
        SDL_Window* m_window = nullptr;
        SDL_Event m_event;
    };

}

}
