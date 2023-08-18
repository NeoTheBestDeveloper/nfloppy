#pragma once

#include <cstdint>
#include <fstream>
#include <iostream>

namespace Nfloppy {

namespace Common {

    class Logger final {
    public:
        static Logger& instance()
        {
            if (not s_intialized) {
                std::cerr << "[PANIC]: trying use unintialized logger. "
                             "Initialise it with 'Logger::init()'!";
            }
            static Logger s_instance;
            return s_instance;
        }

        static void init()
        {
            s_out = &std::cout;
            s_intialized = true;
        }

        static void init(const std::string& path)
        {
            s_file.open(path);
            s_out = &s_file;
        }

        static void destroy()
        {
            if (s_file.is_open()) {
                s_file.close();
            }
        }

        void info(const std::string& msg);
        void warning(const std::string& msg);
        void error(const std::string& msg);
        [[noreturn]] void panic(const std::string& msg);

    private:
        Logger& operator=(Logger const&) = default;
        void write_to_buffer(const char* msg, uint64_t size);

        Logger();

        inline static std::ostream* s_out = nullptr;
        inline static std::ofstream s_file;
        inline static bool s_intialized = false;
    };

}

}
