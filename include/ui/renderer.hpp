#pragma once

#include <string>

#include <SDL.h>
#include <SDL_ttf.h>

#include "math/vec2.hpp"
#include "ui/texture/texture.hpp"

using Nfloppy::Math::Vec2f;

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
            TTF_CloseFont(s_font);
        }

        // Add texture at the buffer.
        void draw(Texture::Texture const&) const;
        void draw(std::string const& msg, Vec2f const& pos,
                  Vec2f const& size) const;

        // Put buffet at the screen.
        void render() const;

        SDL_Texture* create_texture(SDL_Surface*) const;
        SDL_Texture* rotate_texture(SDL_Texture*, double angle) const;

    private:
        Renderer& operator=(Renderer const&) = default;

        inline static SDL_Window* s_win = nullptr;
        inline static int32_t s_logical_width = 0;
        inline static int32_t s_logical_height = 0;

        inline static TTF_Font* s_font = nullptr;
        SDL_Color m_color = { 255, 255, 255, 0 };
        SDL_Renderer* m_renderer = nullptr;

        Renderer();
    };

}

}
