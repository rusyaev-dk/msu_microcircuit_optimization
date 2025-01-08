#include "timer.hpp"

void Timer::start() { _start = Clock::now(); }

void Timer::stop() {
    _wait(1);
    auto end = Clock::now();
    _elapsed_time =
        std::chrono::duration<double, std::milli>(end - _start).count();
}

void Timer::_wait(int milliseconds) const {
    auto start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::high_resolution_clock::now() - start)
               .count() < milliseconds) {
    }
}
