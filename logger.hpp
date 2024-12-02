#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "exceptions.hpp"

enum MCInstruction {
    Write,
    Mul,
    Pow,
};

class InstructionFormatter {
   public:
    static const std::string to_string(MCInstruction instruction) {
        switch (instruction) {
            case Write:
                return "Write";
            case Mul:
                return "Mul";
            case Pow:
                return "Pow";
            default:
                throw MicrocircuitException("Unknown MCInstruction");
        }
    }
};

class InstructionLogger {
    std::ostream* _output_stream;

   public:
    InstructionLogger(std::ostream& output_stream = std::cout)
        : _output_stream(&output_stream) {}

    void log(const std::string& msg) const {
        if (!_output_stream) return;

        (*_output_stream) << msg << std::endl;
    }

    void log(const std::string& msg, const int arg) const {
        if (!_output_stream) return;

        (*_output_stream) << msg << " " << arg << std::endl;
    }

    void log(MCInstruction instruction, const long long arg) const {
        if (!_output_stream) return;

        (*_output_stream) << InstructionFormatter::to_string(instruction) << " "
                          << arg << std::endl;
    }

    void log(MCInstruction instruction) const {
        if (!_output_stream) return;

        (*_output_stream) << InstructionFormatter::to_string(instruction)
                          << std::endl;
    }
};
