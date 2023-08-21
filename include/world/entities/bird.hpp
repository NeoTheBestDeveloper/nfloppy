#pragma once

#include "entity.hpp"
#include "ui/texture/animated_texture.hpp"

using Nfloppy::ui::Texture::AnimatedTexture;

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Bird final : public Entity {
        public:
            Bird(EntityId id, Math::Vec2f const& pos, Math::Vec2f const& size);
            void update(double dt) final;
            Texture const& texture() const final;

        private:
            AnimatedTexture m_texture;
            const double m_base_y;
        };

    }

}

}
