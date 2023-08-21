#pragma once

#include <SDL.h>

#include "math/vec2.hpp"
#include "world/entities/entity_id.hpp"

using Nfloppy::Math::Vec2f;
using Nfloppy::World::Entities::EntityId;

namespace Nfloppy {

namespace ui {

    namespace Texture {

        class Texture {

        public:
            Texture(EntityId id, Vec2f const& pos, Vec2f const& size);
            Texture(Texture&& texture) = default;
            Texture(Texture const&) = delete;
            virtual ~Texture() { }

            void update_pos(Vec2f const& new_pos);

            SDL_Texture* sdl_texture() const;
            const SDL_Rect* sdl_rect() const;

        protected:
            SDL_Texture* m_texture = nullptr;
            SDL_Rect m_box;

            virtual void load(EntityId id) = 0;
        };
    }

}

}
