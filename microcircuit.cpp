#include "microcircuit.hpp"

Microcircuit::Microcircuit() { this->_stack = Stack<int>(); }

void Microcircuit::writeX(int x) { this->_stack.push(x); };

int Microcircuit::mul() {
    
}

int Microcircuit::powN() {}