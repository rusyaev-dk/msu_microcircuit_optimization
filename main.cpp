#include <fstream>
#include <iostream>

#include "microcircuit.hpp"
#include "stack.hpp"

int main() {
    try {
        std::ofstream output_file;
        output_file.open("out.txt");
        if (!output_file.is_open()) {
            std::cout << "Error: file not opened" << std::endl;
            return 1;
        }

        Microcircuit mic = Microcircuit(output_file);
        long long int res = mic.compute_power(2, 45);
        output_file << res;
        output_file.close();

        std::cout << res << "\n";

    } catch (const std::ios_base::failure& e) {
        std::cout << "File I/O error: " << e.what() << std::endl;
    } catch (const MicrocircuitException& e) {
        std::cout << "Microcircuit error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}

// 2^26 = 67108864
// 5^7 = 78125
//
// 2^32, 1

//