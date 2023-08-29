#pragma once

#include <random>

namespace Nfloppy {

namespace Common {

    class RangeRandom final {
    public:
        RangeRandom(int64_t from, int64_t to);

        int64_t generate();

    private:
        std::mt19937 m_gen;
        std::uniform_int_distribution<int64_t> m_dis;
    };

}

}
