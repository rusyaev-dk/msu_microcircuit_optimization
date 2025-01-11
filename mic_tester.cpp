#include "mic_tester.hpp"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <locale>

struct CustomCommaFacet : public std::numpunct<char> {
   protected:
    char do_decimal_point() const override { return ','; }
};

MicTester::MicTester(Microcircuit& mic, const std::string& static_tests_path,
                     const std::string& random_tests_path)
    : _mic(mic),
      _timer(),
      _static_tests_fstream(static_tests_path, std::ios::in),
      _random_tests_fstream(random_tests_path, std::ios::out | std::ios::trunc),
      _metrics(2) {
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

void MicTester::show_metrics() const {
    size_t size = std::min(_metrics[0].size(), _metrics[1].size());

    std::cout.precision(3);
    std::cout << "Test\tBF(Cycles)\tBE(Cycles)\tBF(Ops)\t\tBE(Ops)\t\tBF(ms)"
                 "\tBE(ms)\n";
    for (size_t i = 0; i < size; i++) {
        const Metrics& bf_metrics = _metrics[0][i];
        const Metrics& be_metrics = _metrics[1][i];

        std::cout << i + 1 << "\t" << bf_metrics.cycles << "\t\t"
                  << be_metrics.cycles << "\t\t" << bf_metrics.elementary_ops
                  << "\t\t" << be_metrics.elementary_ops << "\t\t" << std::fixed
                  << bf_metrics.execution_time << "\t"
                  << be_metrics.execution_time << "\n";
    }
}

void MicTester::save_metrics_to_csv(const std::string& filepath) const {
    std::ofstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error(
            "Error: Failed to open file for writing metrics.");
    }

    file.imbue(std::locale(file.getloc(), new CustomCommaFacet));
    file << "Test;BF(Cycles);BE(Cycles);BF(Ops);BE(Ops);BF(ms);BE(ms)\n";
    file << std::fixed << std::setprecision(7);

    size_t size = std::min(_metrics[0].size(), _metrics[1].size());
    for (size_t i = 0; i < size; i++) {
        const Metrics& bf_metrics = _metrics[0][i];
        const Metrics& be_metrics = _metrics[1][i];

        file << (i + 1) << ";" << bf_metrics.cycles << ";" << be_metrics.cycles
             << ";" << bf_metrics.elementary_ops << ";"
             << be_metrics.elementary_ops << ";" << bf_metrics.execution_time
             << ";" << be_metrics.execution_time << "\n";
    }

    file.close();
    std::cout << "Metrics successfully saved to " << filepath << "\n";
}

void MicTester::_run_tests(const std::vector<MicTest>& tests) {
    for (size_t i = 0; i < tests.size(); i++) {
        const MicTest& test = tests[i];

        Metrics bf_mean_metrics = Metrics();
        Metrics be_mean_metrics = Metrics();

        long long res1 = 0;
        long long res2 = 0;
        for (size_t j = 0; j < _SINGLE_TEST_REPEATS; j++) {
            _timer.start();
            res1 = _mic.brute_force_compute(test.n, test.x);
            _timer.stop();

            Metrics cur_test_metrics = _collect_metrics(_mic, _timer.elapsed());
            _timer.reset();
            _mic.clear();

            bf_mean_metrics.cycles = cur_test_metrics.cycles;
            bf_mean_metrics.elementary_ops = cur_test_metrics.elementary_ops;
            bf_mean_metrics.execution_time += cur_test_metrics.execution_time;

            _timer.start();
            res2 = _mic.bin_exp_compute(test.n, test.x);
            _timer.stop();

            cur_test_metrics = _collect_metrics(_mic, _timer.elapsed());
            _timer.reset();
            _mic.clear();

            be_mean_metrics.cycles = cur_test_metrics.cycles;
            be_mean_metrics.elementary_ops = cur_test_metrics.elementary_ops;
            be_mean_metrics.execution_time += cur_test_metrics.execution_time;
        }

        bf_mean_metrics.execution_time /= _SINGLE_TEST_REPEATS;
        be_mean_metrics.execution_time /= _SINGLE_TEST_REPEATS;

        _metrics[0].emplace_back(bf_mean_metrics);
        _metrics[1].emplace_back(be_mean_metrics);

        _validate_answer(res1, res2, test.ans, i + 1);
    }
}

Metrics MicTester::_collect_metrics(const Microcircuit& mic,
                                    const double exec_time) {
    return Metrics(mic.get_cycles(), mic.get_elem_ops(), exec_time);
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
        long long x = 2 + std::rand() % 101;  // Диапазон [0, 100]
        long long n = 1 + std::rand() % 64;   // Диапазон [0, 63]

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

    std::sort(_random_tests.begin(), _random_tests.end(),
              [](const MicTest& a, const MicTest& b) { return a.ans < b.ans; });

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
