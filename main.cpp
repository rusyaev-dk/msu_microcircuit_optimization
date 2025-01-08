#include <iostream>

#include "mic_tester.hpp"
#include "microcircuit.hpp"

int main() {
    try {
        Logger logger("out.txt");
        Microcircuit mic(logger);

        MicTester tester(mic, "static_tests.txt", "random_tests.txt");

        // tester.run_static_tests();
        tester.run_random_tests();

    } catch (const std::ios_base::failure& e) {
        std::cout << "I/O error: " << e.what() << std::endl;
        return -1;
    } catch (const MicrocircuitException& e) {
        std::cout << "Microcircuit error: " << e.what() << std::endl;
        return -2;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
        return -3;
    }

    return 0;
}
