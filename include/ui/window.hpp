#pragma once

#include <SDL.h>

#include "world/entities/entities.hpp"
#include "world/entities/entity.hpp"

using Nfloppy::World::Entities::Entities;
using Nfloppy::World::Entities::Entity;

namespace Nfloppy {

namespace ui {

    class Window final {

        friend class Renderer;

    public:
        Window(const int32_t logical_width, const int32_t logical_height,
               const std::string& title);
        ~Window();

        Window(const Window&) = default;

        void render(const Entities& entities);

        void init();
        bool valid() const;
        const std::string& error() const;

        void toggle_fps();
        void poll_event();
        const SDL_Event& event() const;

    private:
        SDL_Window* m_window = nullptr;
        SDL_Event m_event;

        // TODO: private constructor
        // TODO: const
        std::string m_title;
        int32_t m_logical_width;
        int32_t m_logical_height;

        bool m_is_valid = false;
        std::string m_error = "";
    };

}

}
