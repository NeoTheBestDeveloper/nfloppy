#include <string>

#include "entities/fps_counter.hpp"
#include "font.hpp"

using Nfloppy::Entities::FpsCounter;

FpsCounter::FpsCounter(Math::Vec2f const& pos, Math::Vec2f const& size,
                       bool is_hidden)
    : Entity(pos, size, is_hidden)
    , m_msg(' ', 11)
{
    m_msg = "FPS: 0";
}

void FpsCounter::update(double dt, SDL_Renderer* renderer)
{
    m_fps_timer += dt;

    if (m_fps_timer >= 1.0) {
        m_fps = m_fps_accumulator;
        m_fps_accumulator = 0;
        m_fps_timer = 0.0;

        std::string fps_cnt = std::to_string(m_fps);

        for (size_t i = 0; i < fps_cnt.length(); ++i) {
            m_msg[i + 5] = fps_cnt[i];
        }

        m_msg[fps_cnt.length() + 5] = 0;

        SDL_Surface* fps_counter_surf = TTF_RenderText_Solid(
            Nfloppy::SDL_FONT, m_msg.c_str(), m_font_color);

        m_texture = SDL_CreateTextureFromSurface(renderer, fps_counter_surf);

        SDL_FreeSurface(fps_counter_surf);
    }
}

bool FpsCounter::load_texture(SDL_Renderer* renderer)
{
    SDL_Surface* fps_counter_surf
        = TTF_RenderText_Solid(Nfloppy::SDL_FONT, m_msg.c_str(), m_font_color);

    m_texture = SDL_CreateTextureFromSurface(renderer, fps_counter_surf);

    SDL_FreeSurface(fps_counter_surf);

    return true;
}

void FpsCounter::draw(SDL_Renderer* renderer)
{
    if (not m_is_hidden) {
        SDL_RenderCopy(renderer, m_texture, nullptr, &m_texture_size);
    }

    m_fps_accumulator += 1;
}
