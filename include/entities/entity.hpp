#pragma once

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

#include "math/vec2.hpp"

namespace Nfloppy {

namespace Entities {

    class Entity {
    public:
        Entity(Math::Vec2f const& pos, Math::Vec2f const& size,
               bool hidden = false);
        virtual ~Entity() { }

        Entity(Entity const&) = delete;
        Entity const& operator=(Entity const&) = delete;

        virtual void draw(SDL_Renderer* renderer);
        virtual bool load_texture(SDL_Renderer* renderer) = 0;
        void free_texture();

        virtual void update(double dt, SDL_Renderer*);

        void set_velocity(Math::Vec2f const& v);
        void set_acceleration(Math::Vec2f const& a);

        bool is_hidden() const;
        void hide();
        void show();
        void toggle_hide();

    protected:
        SDL_Texture* m_texture = nullptr;
        SDL_Rect m_texture_size;

        Math::Vec2f m_pos;
        const Math::Vec2f m_size;
        Math::Vec2f m_velocity = .0;
        Math::Vec2f m_acceleration = .0;

        bool m_is_hidden;
    };

}

}
