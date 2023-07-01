#include "entities/fps_counter.hpp"

using Nfloppy::Entities::FpsCounter;

void FpsCounter::update(double dt)
{
    m_fps_timer += dt;

    if (m_fps_timer >= 1.0) {
        m_fps = m_fps_accumulator;
        m_fps_accumulator = 0;
    }
}

bool FpsCounter::load_texture(SDL_Renderer* renderer) { return true; }

void FpsCounter::draw(SDL_Renderer* renderer)
{
    m_fps_accumulator += 1;
    SDL_RenderCopy(renderer, m_texture, nullptr, nullptr);
}
