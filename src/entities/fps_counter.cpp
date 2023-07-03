#include <string>

#include "entities/fps_counter.hpp"
#include "font.hpp"

using Nfloppy::Entities::FpsCounter;

FpsCounter::FpsCounter(Math::Vec2f const& pos, Math::Vec2f const& size)
    : Entity(pos, size)
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

        std::string num = std::to_string(m_fps);

        for (size_t i = 0; i < num.length(); ++i) {
            m_msg[i + 5] = num[i];
        }

        m_msg[num.length() + 5] = 0;

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
    SDL_RenderCopy(renderer, m_texture, nullptr, &m_texture_size);

    m_fps_accumulator += 1;
}
