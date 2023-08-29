#pragma once

#include "entity.hpp"
#include "math/vec2.hpp"
#include "ui/texture/static_texture.hpp"

using Nfloppy::Math::Vec2f;
using Nfloppy::ui::Texture::StaticTexture;

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Pipe final : public Entity {
        public:
            explicit Pipe(Vec2f const& pos);
            void update(double dt) final;
            Texture const& texture() const final;

        private:
            StaticTexture m_texture;

            double get_bottom_pipe_y(double bottom_pipe_height) const;
            double get_upper_pipe_y(double bottom_pipe_height) const;
        };
    }

}

}
