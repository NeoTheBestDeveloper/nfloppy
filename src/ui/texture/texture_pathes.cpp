#include "ui/texture/texture_pathes.hpp"
#include <utility>

using Nfloppy::ui::Texture::TexturePathes;

const std::vector<path>& TexturePathes::operator[](EntityId id) const
{
    return m_pathes.at(id);
}

TexturePathes::TexturePathes()
    : m_pathes(4)
{
    // TODO: absolute pathes for assets with variables.
    m_pathes[EntityId::BACKGROUND] = { "./assets/sprites/background-day.png" };
    m_pathes[EntityId::BASE] = { "./assets/sprites/base.png" };
    m_pathes[EntityId::BIRD] = { "./assets/sprites/yellowbird-downflap.png",
                                 "./assets/sprites/yellowbird-midflap.png",
                                 "./assets/sprites/yellowbird-upflap.png" };
    m_pathes[EntityId::PIPE] = { "./assets/sprites/pipe-green.png" };
}
