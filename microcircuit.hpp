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

    void _brute_force(long long x, long long n);            // O(N)
    void _binary_exponentiation(long long x, long long n);  // O(logN)

    void _write(long long x);
    void _mul();
    void _pow_n(long long n);

   public:
    Microcircuit(Logger& logger);
    long long compute_power(long long x, long long n);

    void clear();
};
