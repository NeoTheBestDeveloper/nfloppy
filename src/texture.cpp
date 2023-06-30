#include "texture.hpp"

using Nfloppy::Texture;

Texture::Texture(std::string const& path)
    : m_path(path)
{
}

char const* Texture::path() const { return m_path.c_str(); }

bool Texture::load(SDL_Renderer* renderer)
{
    SDL_Surface* texture_surf = SDL_LoadBMP(m_path.c_str());
    if (texture_surf == nullptr) {
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(renderer, texture_surf);
    SDL_FreeSurface(texture_surf);
    return true;
}

Texture::~Texture() { SDL_DestroyTexture(m_texture); }

SDL_Texture* Texture::sdl_texture() { return m_texture; }
