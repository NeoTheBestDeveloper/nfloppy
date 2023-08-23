#pragma once

#include <cstdint>
#include <vector>

#include <SDL.h>

#include "math/vec2.hpp"
#include "texture.hpp"
#include "world/entities/entity_id.hpp"

using Nfloppy::Math::Vec2f;
using Nfloppy::World::Entities::EntityId;

namespace Nfloppy {

namespace ui {

    namespace Texture {

        class AnimatedTexture final : public Texture {

        public:
            AnimatedTexture(EntityId id, Vec2f const& pos, Vec2f const& size,
                            double frame_time);
            ~AnimatedTexture();

            void animate(double dt);
            void rotate(double angle) final;

        private:
            void load(EntityId id) final;

            std::vector<SDL_Texture*> m_frames;
            uint64_t m_current_frame = 0;

            double m_frame_time;
            double m_time_accumulator = 0;
        };
    }

}

}
