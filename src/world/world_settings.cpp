#include "world/world_settings.hpp"

using Nfloppy::World::WorldSettings;

WorldSettings::WorldSettings(const int32_t width, const int32_t height)
    : BACKGROUND_POS(0)
    , BACKGROUND_SIZE(width, height)
    , FPS_COUNTER_POS(10, 5)
    , FPS_COUNTER_SIZE(80, 46)
    , BASE_POS(0, height - 112)
    , BASE_SIZE(366, 112)
    , BIRD_POS(width / 2, height / 2)
    , BIRD_SIZE(32, 24)
{
}
