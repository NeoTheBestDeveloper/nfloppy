#include "world/world_settings.hpp"

using Nfloppy::World::WorldSettings;

WorldSettings::WorldSettings(const int32_t width, const int32_t height)
    : BACKGROUND_POS(0)
    , BACKGROUND_SIZE(width, height)
    , FPS_COUNTER_POS(10, 5)
    , FPS_COUNTER_SIZE(80, 46)
    , BASE_POS(0, height - 112)
    , BASE_SIZE(366, 112)
    , BIRD_POS(width / 2.0 - 16.0, height / 2.0)
    , BIRD_SIZE(32, 24)
    , PIPE_POS(0, 0)
    , PIPE_SIZE(52, 320)
    , PIPE_SPACING(width / 2.0 + 52.0 / 2.0)
    , PIPE_HOLE(70)
{
}
