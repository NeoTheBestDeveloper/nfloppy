#pragma once

#include <string>

#include "entity.hpp"

namespace Nfloppy {

namespace Entities {

    class FpsCounter final : public Entity {

    public:
        FpsCounter(Math::Vec2f const& pos, Math::Vec2f const& size);

        void update(double dt, SDL_Renderer*) final;
        bool load_texture(SDL_Renderer* renderer) final;
        void draw(SDL_Renderer* renderer) final;

    private:
        double m_fps_timer = 0.0;
        int32_t m_fps_accumulator = 0;
        int32_t m_fps = 0;

        SDL_Color m_font_color = { 255, 255, 255, 0 };
        std::string m_msg;
    };
}

}
