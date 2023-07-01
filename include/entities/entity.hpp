#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

#include "math/vec2.hpp"

namespace Nfloppy {

namespace Entities {

    class Entity {
    public:
        Entity(Math::Vec2f const& pos, Math::Vec2f const& size);
        virtual ~Entity() { }

        Entity(Entity const&) = delete;
        Entity const& operator=(Entity const&) = delete;

        virtual void draw(SDL_Renderer* renderer);
        virtual bool load_texture(SDL_Renderer* renderer) = 0;
        void free_texture();

        virtual void update(double dt);

        void set_velocity(Math::Vec2f const& v);
        void set_acceleration(Math::Vec2f const& a);

    protected:
        SDL_Texture* m_texture = nullptr;

        Math::Vec2f m_pos;
        Math::Vec2f m_size;
        Math::Vec2f m_velocity = .0;
        Math::Vec2f m_acceleration = .0;
    };

}

}
