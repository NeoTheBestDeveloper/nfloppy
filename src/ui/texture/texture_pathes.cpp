#include "ui/texture/texture_pathes.hpp"
#include <utility>

using Nfloppy::ui::Texture::TexturePathes;

const std::vector<path>& TexturePathes::operator[](EntityId id) const
{
    return m_pathes.at(id);
}

TexturePathes::TexturePathes()
    : m_pathes(9)
{
    // TODO: absolute pathes for assets with variables.
    m_pathes[EntityId::BACKGROUND] = { "./assets/sprites/background-day.png" };
    m_pathes[EntityId::BASE] = { "./assets/sprites/base.png" };
    m_pathes[EntityId::BIRD] = { "./assets/sprites/yellowbird-downflap.png",
                                 "./assets/sprites/yellowbird-midflap.png",
                                 "./assets/sprites/yellowbird-upflap.png" };

    m_pathes[EntityId::TUBE_1_DOWN] = { "./assets/sprites/pipe-green.png" };
    m_pathes[EntityId::TUBE_1_UP] = { "./assets/sprites/pipe-green.png" };
    m_pathes[EntityId::TUBE_2_DOWN] = { "./assets/sprites/pipe-green.png" };
    m_pathes[EntityId::TUBE_2_UP] = { "./assets/sprites/pipe-green.png" };
    m_pathes[EntityId::TUBE_3_DOWN] = { "./assets/sprites/pipe-green.png" };
    m_pathes[EntityId::TUBE_3_UP] = { "./assets/sprites/pipe-green.png" };
}
