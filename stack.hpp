#pragma once
#include <vector>

#include "stack_exception.hpp"

template <typename T = int>
class Stack {
    std::vector<T> _data;
    int _stackDepth;
    int _stackSize;

    inline bool _isEmpty() const { return this->_stackSize == 0; };

   public:
    Stack();
    Stack(const std::vector<T>& data);

    void push(T elem);
    T pop();
    T peek() const;

    inline int size() const { return this->_stackSize; }

    ~Stack();
};