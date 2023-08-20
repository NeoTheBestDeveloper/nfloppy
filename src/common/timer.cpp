#include <ctime>

#include "common/timer.hpp"

using Nfloppy::Common::Timer;

void Timer::start() { m_start_time = current_time(); }

double Timer::elapsed() const { return current_time() - m_start_time; }

void Timer::restart() { m_start_time = current_time(); }

double Timer::current_time() const
{
    return static_cast<double>(clock()) / static_cast<double>(CLOCKS_PER_SEC);
}
