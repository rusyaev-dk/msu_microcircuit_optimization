#pragma once
#include "stack.hpp"

class Microcircuit {
    Stack<int> _stack;

   public:
    Microcircuit();
    void writeX(int x);
    int mul();
    int powN();
};