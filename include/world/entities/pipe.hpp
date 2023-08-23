#pragma once

#include "entity.hpp"
#include "math/vec2.hpp"
#include "ui/texture/static_texture.hpp"

using Nfloppy::Math::Vec2f;
using Nfloppy::ui::Texture::StaticTexture;

namespace Nfloppy {

namespace World {

    namespace Entities {

        enum class PipeDirection {
            UP = 0,
            DOWN = 1,
        };

        class Pipe final : public Entity {
        public:
            Pipe(EntityId id, Vec2f const& pos, Vec2f const& size,
                 PipeDirection direction);
            void update(double dt) final;
            Texture const& texture() const final;

            void set_pos(Vec2f const& new_pos) final
            {
                m_pos = new_pos;
                m_texture.update_pos(new_pos);
            }

        private:
            StaticTexture m_texture;
        };
    }

}

}
