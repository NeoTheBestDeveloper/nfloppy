#pragma once

namespace Nfloppy {

namespace Common {

    class Timer final {
    public:
        void start();
        double elapsed() const;
        void restart();

    private:
        double m_start_time = 0.0;

        double current_time() const;
    };

}

}
