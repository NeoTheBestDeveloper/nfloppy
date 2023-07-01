#pragma once

#include "entity.hpp"

namespace Nfloppy {

namespace Entities {

    class FpsCounter final : public Entity {

    public:
        void update(double dt) final;

        bool load_texture(SDL_Renderer* renderer) final;
        void draw(SDL_Renderer* renderer) final;

    private:
        double m_fps_timer = 0.0;
        int32_t m_fps_accumulator = 0;
        int32_t m_fps = 0;
    };
}

}
