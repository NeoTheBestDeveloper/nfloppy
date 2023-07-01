#pragma once

#include <filesystem>

#include "entity.hpp"

namespace Nfloppy {

namespace Entities {

    class Background final : public Entity {

    public:
        Background(Math::Vec2f const& pos, Math::Vec2f const& size);

        bool load_texture(SDL_Renderer* renderer) final;

    private:
        inline const static std::filesystem::path TEXTURE_PATH {
            "./assets/background.png"
        };
    };
}

}
