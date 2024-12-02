#include <fstream>
#include <iostream>

#include "microcircuit.hpp"
#include "mic_tester.hpp"
#include "stack.hpp"

int main() {
    try {
        std::ofstream output_file;
        output_file.open("out.txt");
        if (!output_file.is_open()) {
            std::cout << "Error: file not opened" << std::endl;
            return 1;
        }

        std::ifstream tests_file;
        tests_file.open("tests.txt");
        if (!tests_file.is_open()) {
            std::cout << "Error: file not opened" << std::endl;
            return 1;
        }

        Microcircuit mic = Microcircuit(output_file);  // output_file
        MicTester tester = MicTester(mic, tests_file);
        tester.run_tests();

        // long long int res = mic.compute_power(2, 26);

        // output_file << res;
        // output_file.close();

        // std::cout << res << "\n";

    } catch (const std::ios_base::failure& e) {
        std::cout << "File I/O error: " << e.what() << std::endl;
    } catch (const MicrocircuitException& e) {
        std::cout << "Microcircuit error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
