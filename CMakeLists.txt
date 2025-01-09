cmake_minimum_required(VERSION 3.5.0)
project(microcircuit VERSION 0.1.0 LANGUAGES C CXX)

add_executable(microcircuit main.cpp microcircuit.cpp logger.cpp mic_tester.cpp timer.cpp)

