#pragma once

#include <SDL.h>

#include "math/vec2.hpp"
#include "world/entities/entity_id.hpp"

using Nfloppy::Math::Vec2f;
using Nfloppy::World::Entities::EntityId;

namespace Nfloppy {

namespace ui {

    namespace Texture {

        class Texture final {

        public:
            Texture(EntityId id, Vec2f size, Vec2f pos);
            ~Texture();

            void load();
            void update_pos(Vec2f new_pos);
            void update_size(Vec2f new_size);

            SDL_Texture* sdl_texture() const;
            const SDL_Rect* sdl_rect() const;

        private:
            SDL_Texture* m_texture = nullptr;
            SDL_Rect m_box;

            const EntityId m_id;
        };
    }

}

}
