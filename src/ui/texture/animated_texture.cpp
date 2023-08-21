#include <format>

#include <SDL_image.h>

#include "common/logger.hpp"
#include "ui/renderer.hpp"
#include "ui/texture/animated_texture.hpp"
#include "ui/texture/texture_pathes.hpp"

using Nfloppy::Common::Logger;
using Nfloppy::ui::Texture::AnimatedTexture;

AnimatedTexture::AnimatedTexture(EntityId id, Vec2f const& pos,
                                 Vec2f const& size, double frame_time)
    : Texture(id, pos, size)
{
    m_frame_time = frame_time;
    load(id);
}

AnimatedTexture::~AnimatedTexture()
{
    for (auto frame : m_frames) {
        SDL_DestroyTexture(frame);
    }
}

void AnimatedTexture::animate(double dt)
{
    m_time_accumulator += dt;

    if (m_time_accumulator >= m_frame_time) {
        m_current_frame += 1;
        if (m_current_frame == m_frames.size()) {
            m_current_frame = 0;
        }
        m_texture = m_frames[m_current_frame];

        m_time_accumulator -= m_frame_time;
    }
}

void AnimatedTexture::load(EntityId id)
{
    Logger& logger = Logger::instance();
    const Renderer& renderer = Renderer::instance();

    const TexturePathes& pathes = TexturePathes::instance();

    for (size_t i = 0; i < pathes[id].size(); ++i) {
        const char* path = pathes[id][i].c_str();

        SDL_Surface* texture_surf = IMG_Load(path);

        if (texture_surf == nullptr) {
            logger.panic(std::format("Failed to load '{}' texture. Cause: ''",
                                     path, IMG_GetError()));
        }

        m_frames.push_back(renderer.create_texture(texture_surf));

        SDL_FreeSurface(texture_surf);
    }

    m_texture = m_frames[0];
}
