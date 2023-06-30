#pragma once

#include <string>

#include <SDL.h>

#include "math/vec2.hpp"
#include "texture.hpp"

namespace Nfloppy {

namespace Entities {

    class Entity {
    public:
        Entity(std::string const& texture_path, Math::Vec2f const& pos);
        virtual ~Entity() { }

        virtual void update(double dt);

        void draw(SDL_Renderer* renderer);
        bool load_texture(SDL_Renderer* renderer);
        char const* texture_path() const;

        void set_velocity(Math::Vec2f const& v);
        void set_acceleration(Math::Vec2f const& a);

    protected:
        Math::Vec2f m_pos;
        Math::Vec2f m_velocity = { .0, .0 };
        Math::Vec2f m_acceleration = { .0, .0 };

        Texture m_texture;
    };

}

}
