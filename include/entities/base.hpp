#pragma once

#include <filesystem>

#include "entity.hpp"

namespace Nfloppy {

namespace Entities {

    class Base final : public Entity {

    public:
        Base(Math::Vec2f const& pos, Math::Vec2f const& size);

        bool load_texture(SDL_Renderer* renderer) final;
        void update(double dt, SDL_Renderer*) final;

    private:
        inline const static std::filesystem::path TEXTURE_PATH {
            "./assets/sprites/base.png"
        };
    };
}

}
