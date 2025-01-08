#include "timer.hpp"

void Timer::start() { _start = Clock::now(); }

void Timer::stop() {
    auto end = Clock::now();
    _elapsed_time =
        std::chrono::duration<double, std::milli>(end - _start).count();
}
