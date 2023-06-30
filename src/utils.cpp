#include <ctime>

#include "utils.hpp"

namespace Nfloppy {

namespace Utils {
    double double_time()
    {
        return static_cast<double>(clock()) / CLOCKS_PER_SEC;
    }
}

}
