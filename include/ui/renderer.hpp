#pragma once

#include <SDL.h>

#include "ui/texture/texture.hpp"

namespace Nfloppy {

namespace ui {

    class Renderer final {

    public:
        static const Renderer& instance()
        {
            static Renderer s_instance;
            return s_instance;
        }

        static void init(SDL_Window* win, int32_t logical_width,
                         int32_t logical_height)
        {
            s_win = win;
            s_logical_width = logical_width;
            s_logical_height = logical_height;
        }

        static void destroy()
        {
            SDL_DestroyRenderer(Renderer::instance().m_renderer);
        }

        // Add texture at the buffer.
        void draw(const Texture::Texture&) const;

        // Put buffet at the screen.
        void render() const;

        SDL_Texture* create_texture(SDL_Surface*) const;

    private:
        Renderer& operator=(Renderer const&) = default;
        SDL_Renderer* m_renderer = nullptr;

        inline static SDL_Window* s_win = nullptr;
        inline static int32_t s_logical_width = 0;
        inline static int32_t s_logical_height = 0;

        Renderer();
    };

}

}
