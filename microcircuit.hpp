#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "logger.hpp"
#include "mc_instruction.hpp"
#include "stack.hpp"

class Microcircuit {
    Stack<long long> _stack;
    Logger& _logger;
    int _cycles;
    int _elementary_ops;

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

    inline int get_cycles() const { return _cycles; }
    inline int get_elem_ops() const { return _elementary_ops; }
};
