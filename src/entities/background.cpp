#include <iostream>

#include <SDL_image.h>

#include "entities/background.hpp"

using Nfloppy::Entities::Background;

Background::Background(Math::Vec2f const& pos, Math::Vec2f const& size)
    : Entity(pos, size)
{
}

bool Background::load_texture(SDL_Renderer* renderer)
{
    SDL_Surface* texture_surf = IMG_Load(Background::TEXTURE_PATH.c_str());
    if (texture_surf == nullptr) {
        std::cout << "[ERROR] Failed to load background texture: "
                  << IMG_GetError() << ".\n";
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(renderer, texture_surf);
    SDL_FreeSurface(texture_surf);

    return true;
}
