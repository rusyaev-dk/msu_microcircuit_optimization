#include "mic_tester.hpp"

#include <climits>
#include <cstdlib>
#include <ctime>

MicTester::MicTester(Microcircuit& mic, const std::string& static_tests_path,
                     const std::string& random_tests_path)
    : _mic(mic),
      _static_tests_fstream(static_tests_path, std::ios::in),
      _random_tests_fstream(random_tests_path,
                            std::ios::out | std::ios::trunc) {
    if (!_static_tests_fstream.is_open()) {
        throw std::runtime_error("Error: Failed to open static tests file.");
    }

    if (!_random_tests_fstream.is_open()) {
        throw std::runtime_error("Error: Failed to open random tests file.");
    }

    _load_tests(_static_tests_fstream, _static_tests);
}

void MicTester::run_static_tests() {
    std::cout << "Running static tests...\n";
    _run_tests(_static_tests);
}

void MicTester::run_random_tests() {
    std::cout << "Generating and running random tests...\n";
    _generate_random_tests();
    _run_tests(_random_tests);
}

void MicTester::_run_tests(const std::vector<MicTest>& tests) {
    for (size_t i = 0; i < tests.size(); ++i) {
        const MicTest& test = tests[i];

        long long res1 = _mic.brute_force_compute(test.n, test.x);
        //
        _mic.clear();

        long long res2 = _mic.bin_exp_compute(test.n, test.x);
        //
        _mic.clear();

        _validate_answer(res1, res2, test.ans, i + 1);
    }
}

void MicTester::_validate_answer(const long long& res1, const long long& res2,
                                 const long long ans,
                                 const int test_num) const {
    std::string approach;
    if (res1 != ans && res2 != ans) {
        approach = "all";
    } else if (res1 != ans) {
        approach = "brute force";
    } else if (res2 != ans) {
        approach = "binary exp";
    }

    if (approach.empty()) {
        std::cout << "- Test " << test_num << " passed\n";
    } else {
        std::cout << "- Test " << test_num << " failed | Correct ans: " << ans
                  << " | Output ans: " << res1 << " | Approach: " << approach
                  << "\n";
    }
}

void MicTester::_generate_random_tests() {
    _random_tests_fstream.seekp(0);
    _random_tests_fstream << _RAND_TESTS_COUNT << "\n";

    std::srand(std::time(nullptr));
    _random_tests.clear();

    for (int i = 0; i < _RAND_TESTS_COUNT; i++) {
        long long x = std::rand() % 101;  // Диапазон [0, 100]
        long long n = std::rand() % 64;   // Диапазон [0, 63]

        if (x == 0) {
            _random_tests_fstream << x << " " << n << " " << 0 << "\n";
            _random_tests.emplace_back(x, n, 0);
            continue;
        }

        if (n == 0) {
            _random_tests_fstream << x << " " << n << " " << 1 << "\n";
            _random_tests.emplace_back(x, n, 1);
            continue;
        }

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

        _random_tests_fstream << x << " " << n << " " << result << "\n";
        _random_tests.emplace_back(x, n, result);
    }

    std::cout << "Random tests successfully generated and loaded.\n";
}

void MicTester::_load_tests(std::fstream& fstream,
                            std::vector<MicTest>& tests) {
    tests.clear();

    int tests_count = 0;
    fstream.seekg(0);
    fstream >> tests_count;

    for (int i = 0; i < tests_count; i++) {
        long long n = 0;
        long long x = 0;
        long long ans = 0;

        fstream >> n >> x >> ans;

        tests.emplace_back(n, x, ans);
    }
}

MicTester::~MicTester() {
    if (_static_tests_fstream.is_open()) {
        _static_tests_fstream.close();
    }

    if (_random_tests_fstream.is_open()) {
        _random_tests_fstream.close();
    }

    delete[] &_mic;
}
