#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "logger.hpp"
#include "stack.hpp"

class Microcircuit {
    Stack<long long int> _stack;
    InstructionLogger _logger;
    long long int _total_cycles;

    void _brute_force(long long int x, long long int n);            // O(N)
    void _binary_exponentiation(long long int x, long long int n);  // O(logN)

    std::vector<long long int> _find_prime_factors(long long int k);
    void _prime_factors_power(long long int x,
                              long long int n);  // O(N^0,5 + m) m - max prime

    void _write(long long int x);
    void _mul();
    void _pow_n(long long int n);

   public:
    Microcircuit(std::ostream& stream = std::cout);
    long long int compute_power(long long int x, long long int n);
};
