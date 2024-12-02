#include "mic_tester.hpp"

MicTester::MicTester(Microcircuit mic, std::ifstream& _tests_file_stream)
    : _mic(mic), _tests_file_stream(&_tests_file_stream) {
    _tests = std::vector<MicTest>();
    _load_tests();
}

void MicTester::_load_tests() {
    int test_count = 0;
    *_tests_file_stream >> test_count;

    for (int i = 0; i < test_count; i++) {
        long long n = 0;
        long long x = 0;
        long long ans = 0;

        *_tests_file_stream >> n;
        *_tests_file_stream >> x;
        *_tests_file_stream >> ans;

        MicTest test(n, x, ans);
        _tests.push_back(test);
    }
}

void MicTester::run_tests() {
    for (int i = 0; i < _tests.size(); i++) {
        MicTest test = _tests[i];
        long long res = _mic.compute_power(test.n, test.x);

        _mic.clear();

        if (res != test.ans) {
            std::cout << "- Test " << i + 1 << " failed\n";
            continue;
        }
        std::cout << "- Test " << i + 1 << " passed\n";
    }
}
