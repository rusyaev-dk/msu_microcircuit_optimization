#include "mic_tester.hpp"

#include <climits>
#include <cstdlib>
#include <ctime>

MicTester::MicTester(Microcircuit& mic, const std::string& static_tests_path,
                     const std::string& random_tests_path)
    : _mic(mic) {
    std::fstream static_tests_file;
    static_tests_file.open(static_tests_path);
    if (!static_tests_file.is_open()) {
        throw std::runtime_error("Error: Failed to open static tests file.");
    }

    _static_tests_fstream = &static_tests_file;
    _static_tests = std::vector<MicTest>();
    _load_tests(_static_tests_fstream, _static_tests);
}

void MicTester::run_static_tests() {
    for (int i = 0; i < _static_tests.size(); i++) {
        MicTest test = _static_tests[i];

        long long res = _mic.compute_power(test.n, test.x);

        _mic.clear();
        if (res != test.ans) {
            std::cout << "- Test " << i + 1
                      << " failed. Correct ans: " << test.ans
                      << " Output ans: " << res << "\n";
            continue;
        }
        std::cout << "- Test " << i + 1 << " passed\n";
    }
}

void MicTester::_generate_random_tests() {
    *_random_tests_fstream << _RAND_TESTS_COUNT << "\n";
    std::srand(std::time(nullptr));

    for (int i = 0; i < _RAND_TESTS_COUNT; i++) {
        long long x = std::rand() % 101;  // Диапазон [0, 100]
        long long n = std::rand() % 64;   // Диапазон [0, 63]

        long long result = 1;
        bool overflow = false;
        for (long long j = 0; j < n; j++) {
            if (result > LLONG_MAX / x) {
                overflow = true;
                break;
            }
            result *= x;
        }

        if (overflow) {
            i--;
            continue;
        }

        *_random_tests_fstream << x << " " << n << " " << result << "\n";
    }

    (*_random_tests_fstream);

    _load_tests(_random_tests_fstream, _random_tests);
    std::cout << "Random tests successfully generated and loaded\n";
}

void MicTester::_load_tests(std::fstream* fstream,
                            std::vector<MicTest>& tests) {
    int tests_count = 0;
    *fstream >> tests_count;

    for (int i = 0; i < tests_count; i++) {
        long long n = 0;
        long long x = 0;
        long long ans = 0;

        *fstream >> n;
        *fstream >> x;
        *fstream >> ans;

        MicTest test(n, x, ans);
        tests.push_back(test);
    }
}

MicTester::~MicTester() {
    (*_static_tests_fstream).close();
    (*_random_tests_fstream).close();

    delete[] &_random_tests;
    delete[] &_static_tests;

    delete &_mic;
}
