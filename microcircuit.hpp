#pragma once
#include "stack.hpp"
#include <vector>

class Microcircuit {
    Stack<int> _stack;

    static std::vector<int> _primeFactors(int n);

   public:
    Microcircuit();
    void writeX(int x);
    int mul();
    int powN(int n);
};