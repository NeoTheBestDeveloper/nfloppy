#include "world/world_settings.hpp"

using Nfloppy::World::WorldSettings;

WorldSettings::WorldSettings()
    : BACKGROUND_POS(0)
    , BACKGROUND_SIZE(WORLD_WIDTH, WORLD_HEIGHT)
    , FPS_COUNTER_POS(10, 5)
    , FPS_COUNTER_SIZE(80, 46)
    , BASE_POS(0, WORLD_HEIGHT - 112)
    , BASE_SIZE(366, 112)
    , BIRD_POS(WORLD_WIDTH / 2.0 - 16.0, WORLD_HEIGHT / 2.0)
    , BIRD_SIZE(32, 24)
    , PIPE_POS(0, 0)
    , PIPE_SIZE(52, 400)
    , PIPE_SPACING(WORLD_WIDTH / 2.0 + 52.0 / 2.0)
    , PIPE_HOLE(80)
{
}
