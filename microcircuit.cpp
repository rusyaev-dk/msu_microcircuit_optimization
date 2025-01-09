#include "microcircuit.hpp"

#include "math.h"

Microcircuit::Microcircuit(Logger& logger) : _logger(logger), _timer() {
    _stack = Stack<long long>();
    _metrics = Metrics();
}

long long Microcircuit::brute_force_compute(long long x, long long n) {
    _timer.start();
    long long res = _pre_compute(x, n);
    if (res != -1) {
        _print_answer(res, 1);
        return res;
    }

    _logger.log(MCInstruction::Write, _stack.peek());
    _write(_stack.peek());
    for (long long i = 1; i < n; i++) {
        _logger.log(MCInstruction::Mul);
        _mul();
    }

    _timer.stop();
    _metrics.execution_time = _timer.elapsed();
    _print_answer(_stack.peek(), _metrics.cycles);
    return _stack.peek();
}

long long Microcircuit::bin_exp_compute(long long x, long long n) {
    _timer.start();
    long long res = _pre_compute(x, n);
    if (res != -1) {
        _print_answer(res, 1);
        return res;
    }

    std::vector<long long> bin;
    while (n > 0) {
        bin.push_back(n % 2);
        n /= 2;
        _metrics.elementary_ops += 2;
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
    
    _timer.stop();
    _metrics.execution_time = _timer.elapsed();
    _print_answer(_stack.peek(), _metrics.cycles);
    return _stack.peek();
}

long long Microcircuit::_pre_compute(long long x, long long n) {
    _metrics = Metrics();
    _stack.clear();

    _logger.log("x = ", x);
    _logger.log("n = ", n);
    _logger.log(MCInstruction::Write, x);

    _write(x);

    if (x == 0 || n == 1) {
        _metrics.cycles = 1;
        _logger.log("Answer: ", x);
        _logger.log("Total cycles: ", 1);
        _logger.log("\n");
        return x;
    } else if (x == 1 || n == 0) {
        _metrics.cycles = 1;
        _logger.log("Answer: ", 1LL);
        _logger.log("Total cycles: ", 1);
        _logger.log("\n");
        return 1ll;
    }
    return -1;
}

void Microcircuit::_write(long long x) {
    // 1 cycle
    _stack.push(x);

    _metrics.cycles++;
};

void Microcircuit::_mul() {
    // 1 cycle
    long long top = _stack.peek();
    long long penultimate = _stack.penultimate();
    _stack.rewrite_top(top * penultimate);

    _metrics.elementary_ops++;
    _metrics.cycles++;
}

void Microcircuit::_pow_n(long long n) {
    // n - 1 cycles
    if (_stack.is_empty()) return;

    long long top = _stack.peek();
    long long result = 1;
    for (long long i = 0; i < n; i++) {
        result *= top;
        _metrics.elementary_ops++;
    }
    _stack.rewrite_top(result);

    _metrics.cycles += n - 1;
}

void Microcircuit::_print_answer(long long ans, int cycles) {
    _logger.log("Answer: ", ans);
    _logger.log("Total cycles: ", cycles);
    _logger.log("\n");
}

void Microcircuit::clear() {
    _stack.clear();
    _timer.reset();
    _metrics = Metrics();
}
