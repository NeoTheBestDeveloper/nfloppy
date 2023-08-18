#include <format>

#include "common/logger.hpp"

using Nfloppy::Common::Logger;

Logger::Logger() { }

void Logger::info(const std::string& msg)
{
    const std::string formatted_msg = std::format("[INFO]: {}\n", msg);
    write_to_buffer(formatted_msg.c_str(), formatted_msg.size());
}

void Logger::warning(const std::string& msg)
{
    const std::string formatted_msg = std::format("[WARNING]: {}\n", msg);
    write_to_buffer(formatted_msg.c_str(), formatted_msg.size());
}

void Logger::error(const std::string& msg)
{
    const std::string formatted_msg = std::format("[ERROR]: {}\n", msg);
    write_to_buffer(formatted_msg.c_str(), formatted_msg.size());
}

[[noreturn]] void Logger::panic(const std::string& msg)
{
    const std::string formatted_msg = std::format("[PANIC]: {}\n", msg);
    write_to_buffer(formatted_msg.c_str(), formatted_msg.size());
    exit(EXIT_FAILURE);
}

void Logger::write_to_buffer(const char* msg, uint64_t size)
{
    s_out->write(msg, static_cast<int64_t>(size));
    s_out->flush();
}
