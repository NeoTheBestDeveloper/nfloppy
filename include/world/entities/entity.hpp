#pragma once

#include <memory>

#include <SDL2/SDL.h>

#include "math/vec2.hpp"
#include "ui/texture/texture.hpp"
#include "world/entities/entity_id.hpp"

using Nfloppy::Math::Vec2f;
using Nfloppy::ui::Texture::Texture;

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Entity {
        public:
            Entity(EntityId id, Vec2f const& pos, Vec2f const& size);
            virtual ~Entity() { }

            Entity(Entity const&) = delete;
            Entity const& operator=(Entity const&) = delete;

            virtual void update(double dt) = 0;
            virtual Texture const& texture() const = 0;

            Vec2f const& size() const;
            Vec2f const& pos() const;

            void set_velocity(Vec2f const& new_velocity);
            void set_acceleration(Vec2f const& new_acceleration);

        protected:
            Vec2f m_pos;
            Vec2f m_size;
            Vec2f m_velocity = .0;
            Vec2f m_acceleration = .0;
        };

        using EntityPtr = std::unique_ptr<Entity>;
    }

}

}
