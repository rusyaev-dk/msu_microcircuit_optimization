#include "timer.hpp"

void Timer::start() { _start = Clock::now(); }

void Timer::stop() {
    // _wait(1);
    auto end = Clock::now();
    _elapsed_time =
        std::chrono::duration<double, std::milli>(end - _start).count();

    const double threshold = 0.0000001;
    double time_in_ms = _elapsed_time / 1'000'000.0;

    if (time_in_ms < threshold) {
        _elapsed_time = 0.01;
    }
}

void Timer::_wait(int milliseconds) const {
    auto start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::high_resolution_clock::now() - start)
               .count() < milliseconds) {
    }
}
