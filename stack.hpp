#pragma once

#include "stack_exception.hpp"

template <typename T>
class Stack {
    T* _data;
    int _stackDepth;
    int _stackSize;

    inline bool _isEmpty() const { return this->_stackSize == 0; };

   public:
    Stack();
    Stack(const Stack<T>& other);

    void push(T elem);
    T pop();
    T peek() const;

    inline int size() const { return this->_stackSize; }

    ~Stack();
};

static const int _DEFAULT_STACK_DEPTH = 100;

template <typename T>
Stack<T>::Stack() : _stackDepth(_DEFAULT_STACK_DEPTH), _stackSize(0) {
    this->_data = new T[_stackDepth];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
    : _stackDepth(other._stackDepth), _stackSize(other._stackSize) {
    this->_data = new T[_stackDepth];
    for (int i = 0; i < _stackSize; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
void Stack<T>::push(T elem) {
    if (_stackSize >= _stackDepth) {
        throw StackException("Stack overflow. Cannot push more elements.");
    }
    _data[_stackSize] = elem;
    this->_stackSize++;
}

template <typename T>
T Stack<T>::pop() {
    if (this->_isEmpty()) {
        throw StackException("Pop() operation aborted: stack is empty.");
    }
    T elem = this->_data[this->_stackSize - 1];
    this->_stackSize--;
    return elem;
}

template <typename T>
T Stack<T>::peek() const {
    if (this->_isEmpty()) {
        throw StackException("Peek() operation aborted: stack is empty.");
    }
    return this->_data[this->_stackSize - 1];
}

template <typename T>
Stack<T>::~Stack() {
    if (this->_data) {
        delete[] _data;
    }
}