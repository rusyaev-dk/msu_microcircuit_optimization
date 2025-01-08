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

class Logger {
    std::fstream _stream;

   public:
    Logger(const std::string& filepath) {
        _stream.open(filepath, std::ios::out);

        if (!_stream.is_open()) {
            throw std::runtime_error(
                "Error: Failed to open logger output file.");
        }
    }

    void log(const std::string& msg) {
        if (!_stream.is_open()) return;

        _stream << msg;
    }

    void log(const std::string& msg, const long long arg) {
        if (!_stream.is_open()) return;

        _stream << msg << arg << "\n";
    }

    void log(const MCInstruction instruction, const long long arg) {
        if (!_stream.is_open()) return;

        _stream << InstructionFormatter::to_string(instruction) << " " << arg
                << "\n";
    }

    void log(const MCInstruction instruction) {
        if (!_stream.is_open()) return;

        _stream << InstructionFormatter::to_string(instruction) << "\n";
    }

    ~Logger() {
        if (_stream.is_open()) {
            _stream.close();
        }
    }
};
