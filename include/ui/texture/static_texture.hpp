#pragma once

#include <SDL.h>

#include "math/vec2.hpp"
#include "texture.hpp"
#include "world/entities/entity_id.hpp"

using Nfloppy::Math::Vec2f;
using Nfloppy::World::Entities::EntityId;

namespace Nfloppy {

namespace ui {

    namespace Texture {

        class StaticTexture final : public Texture {

        public:
            StaticTexture(EntityId id, Vec2f const& pos, Vec2f const& size);
            ~StaticTexture();

            void rotate(double angle) final;

        private:
            void load(EntityId id) final;
        };
    }

}

}
