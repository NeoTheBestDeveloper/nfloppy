#pragma once

#include "entity.hpp"
#include "ui/texture/static_texture.hpp"

using Nfloppy::ui::Texture::StaticTexture;

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Base final : public Entity {

        public:
            Base(EntityId id, Math::Vec2f const& pos, Math::Vec2f const& size);
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
