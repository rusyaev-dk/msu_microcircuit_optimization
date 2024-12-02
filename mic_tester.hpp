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
    Microcircuit _mic;
    std::ifstream* _tests_file_stream;

    std::vector<MicTest> _tests;
    void _load_tests();

   public:
    MicTester(Microcircuit mic, std::ifstream& _tests_file_stream);

    void run_tests();
};