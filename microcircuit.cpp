#include "microcircuit.hpp"

#include "math.h"

Microcircuit::Microcircuit(Logger& logger) : _logger(logger) {
    _stack = Stack<long long>();
    _total_cycles = 0;
}

long long Microcircuit::compute_power(long long x, long long n) {
    _logger.log("x = ", x);
    _logger.log("n = ", n);

    _logger.log(MCInstruction::Write, x);
    _write(x);

    if (x == 0 || n == 1) {
        _logger.log("Answer: ", x);
        _logger.log("Total cycles: ", 1);
        _logger.log("\n");
        return x;
    } else if (x == 1 || n == 0) {
        _logger.log("Answer: ", 1LL);
        _logger.log("Total cycles: ", 1);
        _logger.log("\n");
        return 1ll;
    }

    _binary_exponentiation(x, n);
    // _brute_force(x, n);

    _logger.log("Answer: ", _stack.peek());
    _logger.log("Total cycles: ", _total_cycles);
    _logger.log("\n");

    _total_cycles = 0;

    return _stack.peek();
}

void Microcircuit::_brute_force(long long x, long long n) {
    _logger.log(MCInstruction::Write, _stack.peek());
    _write(_stack.peek());
    for (long long i = 1; i < n; i++) {
        _logger.log(MCInstruction::Mul);
        _mul();
    }
}

void Microcircuit::_binary_exponentiation(long long x, long long n) {
    std::vector<long long> bin;
    while (n > 0) {
        bin.push_back(n % 2);
        n /= 2;
    }

    for (long long i = bin.size() - 2; i >= 0; i--) {
        // Начинаем с предпоследнего бита
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

void Microcircuit::_write(long long x) {
    // 1 cycle
    _stack.push(x);

    _total_cycles++;
};

void Microcircuit::_mul() {
    // 1 cycle
    long long top = _stack.peek();
    long long penultimate = _stack.penultimate();
    _stack.rewrite_top(top * penultimate);

    _total_cycles++;
}

void Microcircuit::_pow_n(long long n) {
    // n - 1 cycles
    if (_stack.is_empty()) return;

    long long top = _stack.peek();
    long long result = 1;
    for (long long i = 0; i < n; ++i) {
        result *= top;
    }
    _stack.rewrite_top(result);

    _total_cycles += n - 1;
}

void Microcircuit::clear() {
    _stack.clear();
    _total_cycles = 0;
}
