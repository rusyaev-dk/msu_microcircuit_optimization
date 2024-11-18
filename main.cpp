#include <iostream>

#include "microcircuit.hpp"
#include "stack.hpp"

int main() {
    try {
        Microcircuit mic;
        int res = mic.compute_power(2, 26);
        std::cout << res << "\n";

    } catch (const MicrocircuitException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

// 2^26 = 67108864
// 5^7 = 78125