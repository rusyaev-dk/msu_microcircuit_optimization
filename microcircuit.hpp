#pragma once
#include <vector>

#include "stack.hpp"

class Microcircuit {
    Stack<int> _stack;
    int _total_cycles;

    void _brute_force_approach(int x, int n);  // O(N)

    std::vector<int> _find_prime_factors(int k);
    void _prime_factors_approach(int x,
                                 int n);  // O(N^0,5 + m) m - max prime
    void _binary_exponentiation_approach(int x, int n);  // O(logN)

    void _write(int x);
    void _mul();
    void _pow_n(int n);

   public:
    Microcircuit();
    int compute_power(int x, int n);
};