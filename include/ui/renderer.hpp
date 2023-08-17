#pragma once

#include <string>

#include <SDL.h>

#include "SDL_render.h"
#include "ui/texture/texture.hpp"
#include "ui/window.hpp"

namespace Nfloppy {

namespace ui {

    class Renderer final {

    public:
        static const Renderer& instance()
        {
            static Renderer s_instance(s_win);
            return s_instance;
        }

        static void init(Window* win) { s_win = win; }
        static void destroy()
        {
            SDL_DestroyRenderer(Renderer::instance().m_renderer);
        }

        bool valid() const;
        const std::string& error() const;

        // Add texture at the buffer.
        void draw(const Texture::Texture&) const;

        // Put buffet at the screen.
        void render() const;

        SDL_Texture* create_texture(SDL_Surface*) const;

    private:
        Renderer& operator=(Renderer const&) = default;
        SDL_Renderer* m_renderer = nullptr;

        inline static Window* s_win = nullptr;

        std::string m_error = "";
        bool m_is_valid = false;

        Renderer(const Window*);
    };

}

}
