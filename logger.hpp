#pragma once

#include <fstream>

#include "exceptions.hpp"
#include "mc_instruction.hpp"

class Logger {
    std::fstream _stream;

   public:
    Logger(const std::string& filepath);

    void log(const std::string& msg);
    void log(const std::string& msg, const long long arg);
    void log(const MCInstruction instruction, const long long arg);
    void log(const MCInstruction instruction);

    ~Logger();
};
