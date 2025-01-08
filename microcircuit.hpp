#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "logger.hpp"
#include "stack.hpp"

class Microcircuit {
    Stack<long long> _stack;
    Logger& _logger;
    long long _total_cycles;

    long long _pre_compute(long long x, long long n);

    void _write(long long x);
    void _mul();
    void _pow_n(long long n);

    void _print_answer(long long ans, int cycles);

   public:
    Microcircuit(Logger& logger);

    long long brute_force_compute(long long x, long long n);  // O(N)
    long long bin_exp_compute(long long x, long long n);      // O(logN)

    void clear();

    inline int get_cycles() const { return _total_cycles; };
};
