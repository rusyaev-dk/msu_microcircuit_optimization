#pragma once

#include <fstream>

#include "microcircuit.hpp"
#include "timer.hpp"

struct Metrics {
    int cycles;
    int elementary_ops;
    double execution_time;

    Metrics() : cycles(0), elementary_ops(0), execution_time(0.0) {}

    Metrics(int c, int ops, double time)
        : cycles(c), elementary_ops(ops), execution_time(time) {}
};

struct MicTest {
    long long n;
    long long x;
    long long ans;

    MicTest(long long n_val, long long x_val, long long ans_val)
        : n(n_val), x(x_val), ans(ans_val) {}
};

class MicTester {
    static const int _RAND_TESTS_COUNT = 100000;
    static const int _SINGLE_TEST_REPEATS = 100;

    Microcircuit _mic;
    Timer _timer;

    std::fstream _static_tests_fstream;
    std::fstream _random_tests_fstream;

    std::vector<MicTest> _static_tests;
    std::vector<MicTest> _random_tests;

    std::vector<std::vector<Metrics>> _metrics;

    void _load_tests(std::fstream& fstream, std::vector<MicTest>& tests);
    void _generate_random_tests();

    void _run_tests(const std::vector<MicTest>& tests);
    Metrics _collect_metrics(const Microcircuit& mic, const double exec_time);
    void _validate_answer(const long long& res1, const long long& res2,
                          const long long ans, const int test_num) const;

   public:
    MicTester(Microcircuit& mic, const std::string& static_tests_path,
              const std::string& random_tests_path);

    void run_static_tests();
    void run_random_tests();

    void show_metrics() const;
    void save_metrics_to_csv(const std::string& filepath) const;

    ~MicTester();
};
