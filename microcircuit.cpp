#include "microcircuit.hpp"

#include <iostream>

#include "math.h"

Microcircuit::Microcircuit() {
    _stack = Stack<int>();
    _total_cycles = 0;
}

void Microcircuit::_write(int x) {
    _stack.push(x);
    
    _total_cycles++;
};

void Microcircuit::_mul() {
    int top = _stack.peek();
    int preTop = _stack.penultimate();
    _stack.replace_top(top * preTop);

    _total_cycles++;
}

void Microcircuit::_pow_n(int n) {
    if (_stack.is_empty()) return;

    int base = _stack.peek();
    _stack.pop();
    _stack.push(base);

    for (int i = 1; i < n; i++) {
        _stack.push(base);
        _mul();
    }
}

void Microcircuit::_brute_force(int x, int n) {
    _write(_stack.peek());
    for (int i = 1; i < n; ++i) {
        _mul();
    }
}

std::vector<int> Microcircuit::_find_prime_factors(int k) {
    std::vector<int> prime_factors;

    if (k <= 1) {
        prime_factors[0] = k;
        return prime_factors;
    }

    while (k % 2 == 0) {
        prime_factors.push_back(2);
        k /= 2;
    }

    for (int i = 3; i <= sqrt(k); i += 2) {
        while (k % i == 0) {
            prime_factors.push_back(i);
            k /= i;
        }
    }

    if (k > 2) {
        prime_factors.push_back(k);
    }

    return prime_factors;
}

void Microcircuit::_prime_factors_power(int x, int n) {
    std::vector<int> prime_factors = _find_prime_factors(n);

    for (int i = 0; i < prime_factors.size(); i++) {
        int top = _stack.peek();
        _stack.push(top);
        for (int j = 0; j < prime_factors[i] - 1; j++) {
            _mul();
        }
    }
}

void Microcircuit::_binary_exponentiation(int x, int n) {
    std::vector<int> bin;
    while (n > 0) {
        bin.push_back(n % 2);
        n /= 2;
    }

    for (int i = bin.size() - 2; i >= 0; --i) {
        _pow_n(2);
        if (bin[i] == 1) {
            _write(x);
            _mul();
        }
    }
}

int Microcircuit::compute_power(int x, int n) {
    _write(x);
    // _brute_force_approach(x, n);
    // _prime_factors_approach(x, n);
    // _binary_exponentiation_approach(x, n);

    std::cout << "Total cycles: " << _total_cycles << std::endl;
    _total_cycles = 0;
    return _stack.peek();
}