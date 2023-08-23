
#include "world/world.hpp"
#include "world/entities/pipe.hpp"

using Nfloppy::World::World;
using Nfloppy::World::Entities::Background;
using Nfloppy::World::Entities::Base;
using Nfloppy::World::Entities::Bird;
using Nfloppy::World::Entities::Entities;
using Nfloppy::World::Entities::EntityId;
using Nfloppy::World::Entities::Pipe;
using Nfloppy::World::Entities::PipeDirection;

World::World(const int32_t width, const int32_t height)
    : m_entities(9)
    , m_settings(width, height)
    , m_width(width)
    , m_height(height)
    , m_dis(50, 300)
{
    std::random_device dev;
    m_gen = std::mt19937(dev());

    m_entities[EntityId::BACKGROUND] = make_background();
    m_entities[EntityId::BASE] = make_base();
    m_entities[EntityId::BIRD] = make_bird();

    make_tubes();

    init_level();
}

void World::make_tubes()
{
    m_entities[EntityId::TUBE_1_UP] = make_tube(EntityId::TUBE_1_UP);
    m_entities[EntityId::TUBE_1_DOWN] = make_tube(EntityId::TUBE_1_DOWN);
    m_entities[EntityId::TUBE_2_UP] = make_tube(EntityId::TUBE_2_UP);
    m_entities[EntityId::TUBE_2_DOWN] = make_tube(EntityId::TUBE_2_DOWN);
    m_entities[EntityId::TUBE_3_UP] = make_tube(EntityId::TUBE_3_UP);
    m_entities[EntityId::TUBE_3_DOWN] = make_tube(EntityId::TUBE_3_DOWN);
}

double World::gen_up_pipe_heigth()
{
    return static_cast<double>(m_dis(m_gen));
}

double World::get_up_pipe_y(double up_pipe_heigth) const
{
    return m_settings.BACKGROUND_SIZE.y - m_settings.BASE_SIZE.y
        - up_pipe_heigth;
}

double World::get_down_pipe_y(double up_pipe_heigth) const
{
    return -(m_settings.PIPE_SIZE.y
             - (m_settings.BACKGROUND_SIZE.y - m_settings.BASE_SIZE.y
                - m_settings.PIPE_HOLE - up_pipe_heigth));
}

void World::init_level()
{
    double first_up_pipe_height = gen_up_pipe_heigth();
    m_entities[EntityId::TUBE_1_UP]->set_pos(
        { m_width + m_settings.PIPE_SPACING,
          get_up_pipe_y(first_up_pipe_height) });
    m_entities[EntityId::TUBE_1_DOWN]->set_pos(
        { m_width + m_settings.PIPE_SPACING,
          get_down_pipe_y(first_up_pipe_height) });

    double second_up_pipe_height = gen_up_pipe_heigth();
    m_entities[EntityId::TUBE_2_UP]->set_pos(
        { m_width + m_settings.PIPE_SPACING * 2,
          get_up_pipe_y(second_up_pipe_height) });
    m_entities[EntityId::TUBE_2_DOWN]->set_pos(
        { m_width + m_settings.PIPE_SPACING * 2,
          get_down_pipe_y(second_up_pipe_height) });

    double third_up_pipe_height = gen_up_pipe_heigth();
    m_entities[EntityId::TUBE_3_UP]->set_pos(
        { m_width + m_settings.PIPE_SPACING * 3,
          get_up_pipe_y(third_up_pipe_height) });
    m_entities[EntityId::TUBE_3_DOWN]->set_pos(
        { m_width + m_settings.PIPE_SPACING * 3,
          get_down_pipe_y(third_up_pipe_height) });
}

void World::update(const double dt)
{
    for (auto& entity : m_entities) {
        entity->update(dt);
    }

    if (m_entities[EntityId::TUBE_1_UP]->pos().x <= -52) {
        double new_up_pipe_height = gen_up_pipe_heigth();
        double new_x = m_entities[EntityId::TUBE_3_DOWN]->pos().x
            + m_settings.PIPE_SPACING;
        m_entities[EntityId::TUBE_1_DOWN]->set_pos(
            { new_x, get_down_pipe_y(new_up_pipe_height) });
        m_entities[EntityId::TUBE_1_UP]->set_pos(
            { new_x, get_up_pipe_y(new_up_pipe_height) });
    }

    if (m_entities[EntityId::TUBE_2_UP]->pos().x <= -52) {
        double new_up_pipe_height = gen_up_pipe_heigth();
        double new_x = m_entities[EntityId::TUBE_1_DOWN]->pos().x
            + m_settings.PIPE_SPACING;
        m_entities[EntityId::TUBE_2_DOWN]->set_pos(
            { new_x, get_down_pipe_y(new_up_pipe_height) });
        m_entities[EntityId::TUBE_2_UP]->set_pos(
            { new_x, get_up_pipe_y(new_up_pipe_height) });
    }

    if (m_entities[EntityId::TUBE_3_UP]->pos().x <= -52) {
        double new_up_pipe_height = gen_up_pipe_heigth();
        double new_x = m_entities[EntityId::TUBE_2_DOWN]->pos().x
            + m_settings.PIPE_SPACING;
        m_entities[EntityId::TUBE_3_DOWN]->set_pos(
            { new_x, get_down_pipe_y(new_up_pipe_height) });
        m_entities[EntityId::TUBE_3_UP]->set_pos(
            { new_x, get_up_pipe_y(new_up_pipe_height) });
    }
}

const Entities& World::entities() const { return m_entities; }

EntityPtr World::make_background() const
{
    return std::make_unique<Background>(EntityId::BACKGROUND,
                                        m_settings.BACKGROUND_POS,
                                        m_settings.BACKGROUND_SIZE);
}

EntityPtr World::make_base() const
{
    return std::make_unique<Base>(EntityId::BASE, m_settings.BASE_POS,
                                  m_settings.BASE_SIZE);
}

EntityPtr World::make_bird() const
{
    return std::make_unique<Bird>(EntityId::BIRD, m_settings.BIRD_POS,
                                  m_settings.BIRD_SIZE);
}

PipeDirection World::get_pipe_direction(EntityId id) const
{
    return (id == EntityId::TUBE_1_UP) or (id == EntityId::TUBE_2_UP)
            or (id == EntityId::TUBE_3_UP)
        ? PipeDirection::UP
        : PipeDirection::DOWN;
}

EntityPtr World::make_tube(EntityId id) const
{
    PipeDirection direction = get_pipe_direction(id);
    return std::make_unique<Pipe>(id, m_settings.PIPE_POS,
                                  m_settings.PIPE_SIZE, direction);
}
