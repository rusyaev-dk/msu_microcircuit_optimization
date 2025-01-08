#pragma once

#include "exceptions.hpp"

template <typename T>
class Stack {
    T* _data;
    int _max_size;
    int _cur_size;

   public:
    Stack();
    Stack(const Stack<T>& other);

    void push(T elem);
    void rewrite_top(T elem);
    T pop();
    T peek() const;
    T penultimate() const;  // Предпоследний сверху элемент

    inline int size() const { return this->_cur_size; }
    inline bool is_empty() const { return this->_cur_size == 0; };

    void clear();

    ~Stack();
};

static const int _DEFAULT_STACK_MAX_SIZE = 10000;

template <typename T>
Stack<T>::Stack() : _max_size(_DEFAULT_STACK_MAX_SIZE), _cur_size(0) {
    _data = new T[_max_size];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
    : _max_size(other._max_size), _cur_size(other._cur_size) {
    _data = new T[_max_size];

    for (int i = 0; i < _cur_size; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
void Stack<T>::push(T elem) {
    if (_cur_size >= _max_size) {
        throw MicrocircuitException(
            "Stack overflow. Unable to push more elements.");
    }

    _data[_cur_size] = elem;
    _cur_size++;
}

template <typename T>
void Stack<T>::rewrite_top(T elem) {
    if (_cur_size > 1) {
        _data[_cur_size - 1] = elem;
    } else {
        _data[0] = elem;
    }
}

template <typename T>
T Stack<T>::pop() {
    if (this->is_empty()) {
        throw MicrocircuitException("pop() operation aborted: stack is empty.");
    }

    T elem = _data[_cur_size - 1];
    _cur_size--;
    return elem;
}

template <typename T>
T Stack<T>::peek() const {
    if (this->is_empty()) {
        throw MicrocircuitException(
            "peek() operation aborted: stack is empty.");
    }

    return _data[_cur_size - 1];
}

template <typename T>
T Stack<T>::penultimate() const {
    if (this->is_empty()) {
        throw MicrocircuitException(
            "penultimate() operation aborted: stack is empty.");
    } else if (_cur_size < 2) {
        throw MicrocircuitException(
            "penultimate() operation aborted: stackSize is less than 2.");
    }

    return _data[_cur_size - 2];
}

template <typename T>
void Stack<T>::clear() {
    _cur_size = 0;
}

template <typename T>
Stack<T>::~Stack() {
    if (_data) {
        delete[] _data;
    }
}
