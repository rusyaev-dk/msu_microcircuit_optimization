#pragma once
#include <chrono>

class Timer {
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    TimePoint _start;
    double _elapsed_time;

   public:
    Timer() : _elapsed_time(0.0) {}

    void start();
    void stop();
    inline void reset() { _elapsed_time = 0.0; }
    inline double elapsed() const { return _elapsed_time; };
};
