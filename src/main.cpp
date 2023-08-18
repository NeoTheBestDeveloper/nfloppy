#include "common/logger.hpp"
#include "game.hpp"

using Nfloppy::Common::Logger;

int main(void)
{
    Logger::init();

    Nfloppy::Game game;
    game.start();

    return 0;
}
