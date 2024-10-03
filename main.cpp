#include <iostream>

#include "stack.hpp"

int main() {
    try {
        Stack<int> myStack{};
        for (int i = 0; i < 100; i++) {
            myStack.push(i);
        }
        for (int i = 0; i < 100; i++) {
            std::cout << myStack.peek();
            myStack.pop();
        }
    } catch (StackException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}