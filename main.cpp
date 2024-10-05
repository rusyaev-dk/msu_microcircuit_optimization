#include <iostream>

#include "microcircuit.hpp"
#include "stack.hpp"

int main() {
    try {
        Microcircuit mic;
        mic.writeX(5);
        int res = mic.powN(6);
        std::cout << res << "\n";

    } catch (const MicrocircuitException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}