#include "common/range_random.hpp"

using Nfloppy::Common::RangeRandom;

RangeRandom::RangeRandom(int64_t from, int64_t to)
    : m_dis(from, to)
{
    std::random_device dev;
    m_gen = std::mt19937(dev());
}

int64_t RangeRandom::generate() { return m_dis(m_gen); }
