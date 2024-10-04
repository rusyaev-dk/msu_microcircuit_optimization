#include <iostream>

#include "stack.hpp"

int main() {
    try {
        Stack<int> myStack;
        for (int i = 0; i < 10; i++) {
            myStack.push(i);
        }
        for (int i = 0; i < 10; i++) {
            std::cout << myStack.pop();
        }
    } catch (const StackException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}