#include "microcircuit.hpp"

#include "math.h"

Microcircuit::Microcircuit(std::ostream& stream)
    : _logger(InstructionLogger(stream)) {
    _stack = Stack<long long int>();

    _total_cycles = 0;
}

long long int Microcircuit::compute_power(long long int x, long long int n) {
    if (n == 1) return x;

    _logger.log(MCInstruction::Write, x);
    _write(x);

    // _binary_exponentiation(x, n);
    _brute_force(x, n);

    _logger.log("Total cycles:", _total_cycles);
    _total_cycles = 0;
    return _stack.peek();
}

void Microcircuit::_brute_force(long long int x, long long int n) {
    _write(_stack.peek());
    for (long long int i = 1; i < n; i++) {
        _logger.log(MCInstruction::Mul);
        _mul();
    }
}

void Microcircuit::_binary_exponentiation(long long int x, long long int n) {
    std::vector<long long int> bin;
    while (n > 0) {
        bin.push_back(n % 2);
        n /= 2;
    }

    for (long long int i = bin.size() - 2; i >= 0; --i) {
        _logger.log(MCInstruction::Pow, 2);
        _pow_n(2);
        if (bin[i] == 1) {
            _logger.log(MCInstruction::Write, x);
            _write(x);

            _logger.log(MCInstruction::Mul);
            _mul();
        }
    }
}

void Microcircuit::_write(long long int x) {
    _stack.push(x);

    _total_cycles++;
};

void Microcircuit::_mul() {
    long long int top = _stack.peek();
    long long int preTop = _stack.penultimate();
    _stack.rewrite_top(top * preTop);

    _total_cycles++;
}

void Microcircuit::_pow_n(long long int n) {
    if (_stack.is_empty()) return;

    // переделать под _write и так далее...
    long long int base = _stack.peek();
    _stack.pop();
    _stack.push(base);

    for (long long int i = 1; i < n; i++) {
        _stack.push(base);  // write
        _mul();
    }
}

std::vector<long long int> Microcircuit::_find_prime_factors(long long int k) {
    std::vector<long long int> prime_factors;

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

void Microcircuit::_prime_factors_power(long long int x, long long int n) {
    std::vector<long long int> prime_factors = _find_prime_factors(n);

    for (int i = 0; i < prime_factors.size(); i++) {
        int top = _stack.peek();
        _stack.push(top);
        for (int j = 0; j < prime_factors[i] - 1; j++) {
            _mul();
        }
    }
}
