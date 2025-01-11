#pragma once
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
