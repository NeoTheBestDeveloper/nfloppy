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

            virtual void update(double dt);

            const Vec2f& size() const;
            const Vec2f& pos() const;
            const Texture& texture() const;

        protected:
            Vec2f m_pos;
            const Vec2f m_size;
            Vec2f m_velocity = .0;
            Vec2f m_acceleration = .0;

            Texture m_texture;
        };

        using EntityPtr = std::unique_ptr<Entity>;
    }

}

}
