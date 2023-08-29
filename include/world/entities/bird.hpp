#pragma once

#include "entity.hpp"
#include "ui/texture/animated_texture.hpp"

using Nfloppy::ui::Texture::AnimatedTexture;

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Bird final : public Entity {
        public:
            Bird();
            void update(double dt) final;
            Texture const& texture() const final;

            void activate();
            void jump();

        private:
            AnimatedTexture m_texture;
            const double m_base_y;
            bool m_active = false;
        };

    }

}

}
