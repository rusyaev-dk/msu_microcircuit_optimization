#include "logger.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Logger::Logger(const std::string& filepath) {
    _stream.open(filepath, std::ios::out);

    if (!_stream.is_open()) {
        throw std::runtime_error("Error: Failed to open logger output file.");
    }
}

void Logger::log(const std::string& msg) {
    if (!_stream.is_open()) return;

    _stream << msg;
}

void Logger::log(const std::string& msg, const long long arg) {
    if (!_stream.is_open()) return;

    _stream << msg << arg << "\n";
}

void Logger::log(const MCInstruction instruction, const long long arg) {
    if (!_stream.is_open()) return;

    _stream << InstructionFormatter::to_string(instruction) << " " << arg
            << "\n";
}

void Logger::log(const MCInstruction instruction) {
    if (!_stream.is_open()) return;

    _stream << InstructionFormatter::to_string(instruction) << "\n";
}

Logger::~Logger() {
    if (_stream.is_open()) {
        _stream.close();
    }
}
