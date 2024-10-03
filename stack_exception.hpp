#pragma once
#include <string>

class StackException {
    std::string _msg;

   public:
    StackException(const std::string& msg) : _msg(msg) {}

    const char* what() const { return _msg.c_str(); }
};
