#include <iostream>

#include "stack.hpp"

int main() {
    try {
        StackTest<int> myStack;
        for (int i = 0; i < 10; i++) {
            myStack.push(i);
        }
        for (int i = 0; i < 10; i++) {
            int peekA = myStack.peek();
            std::cout << peekA;
            std::cout << myStack.pop();
        }
    } catch (const StackException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}