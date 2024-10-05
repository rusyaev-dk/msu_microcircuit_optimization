#include "microcircuit.hpp"

#include <iostream>

#include "math.h"

Microcircuit::Microcircuit() { this->_stack = Stack<int>(); }

void Microcircuit::writeX(int x) { this->_stack.push(x); };

int Microcircuit::mul() {
    int top = this->_stack.getTop();
    int preTop = this->_stack.getPreTop();
    this->_stack.replaceTop(top * preTop);
}

int Microcircuit::powN(int n) {
    std::vector<int> primeFactors = this->_primeFactors(n);

    for (int i = 0; i < primeFactors.size(); i++) {
        std::cout << primeFactors[i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < primeFactors.size(); i++) {
        int top = this->_stack.getTop();
        this->_stack.push(top);
        for (int j = 0; j < primeFactors[i] - 1; j++) {
            this->mul();
        }
    }

    return this->_stack.getTop();
}

std::vector<int> Microcircuit::_primeFactors(int n) {
    std::vector<int> factorsArr;

    if (n <= 1) {
        factorsArr[0] = n;
        return factorsArr;
    }

    while (n % 2 == 0) {
        factorsArr.push_back(2);
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factorsArr.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        factorsArr.push_back(n);
    }

    return factorsArr;
}