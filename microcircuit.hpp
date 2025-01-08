#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "logger.hpp"
#include "stack.hpp"
#include "timer.hpp"

struct Metrics {
    int cycles;
    int elementary_ops;
    double execution_time;

    Metrics() : cycles(0), elementary_ops(0), execution_time(0.0) {}

    Metrics(int c, int ops, double time)
        : cycles(c), elementary_ops(ops), execution_time(time) {}
};

class Microcircuit {
    Stack<long long> _stack;
    Logger& _logger;
    Timer _timer;
    Metrics _metrics;

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

    inline Metrics get_metrics() const { return _metrics; }
};
