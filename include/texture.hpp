#pragma once

#include <SDL.h>
#include <filesystem>

namespace Nfloppy {

class Texture final {

public:
    Texture(std::string const& path);
    ~Texture();

    Texture(Texture const&) = delete;
    Texture operator=(Texture const&) = delete;

    bool load(SDL_Renderer* render);
    char const* path() const;
    SDL_Texture* sdl_texture();

private:
    SDL_Texture* m_texture = nullptr;

    const std::filesystem::path m_path;
};

}
