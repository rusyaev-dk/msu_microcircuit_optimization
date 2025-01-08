#pragma once

#include <fstream>

#include "microcircuit.hpp"

struct MicTest {
    long long n;
    long long x;
    long long ans;

    MicTest(long long n_val, long long x_val, long long ans_val)
        : n(n_val), x(x_val), ans(ans_val) {}
};

class MicTester {
    static const int _RAND_TESTS_COUNT = 40;

    Microcircuit _mic;
    std::fstream _static_tests_fstream;
    std::fstream _random_tests_fstream;

    std::vector<MicTest> _static_tests;
    std::vector<MicTest> _random_tests;

    void _load_tests(std::fstream& fstream, std::vector<MicTest>& tests);
    void _generate_random_tests();

    void _run_tests(const std::vector<MicTest>& tests);
    void _validate_answer(const long long& res1, const long long& res2,
                          const long long ans, const int test_num) const;

   public:
    MicTester(Microcircuit& mic, const std::string& static_tests_path,
              const std::string& random_tests_path);

    void run_static_tests();
    void run_random_tests();

    ~MicTester();
};