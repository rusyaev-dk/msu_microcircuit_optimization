#include <stack.hpp>

static const int _DEFAULT_STACK_DEPTH = 10000;

template <typename T>
Stack<T>::Stack() : _stackDepth(_DEFAULT_STACK_DEPTH), _stackSize(0) {
    this->_data = new std::vector<T>[10];
}

template <typename T>
Stack<T>::Stack(const std::vector<T>& data)
    : _stackDepth(_DEFAULT_STACK_DEPTH) {
    if (data.size() > _DEFAULT_STACK_DEPTH) {
        throw StackException("Incorrect stack size.");
    }

    this->_stackSize = data.size();
    this->_data = data;
}

template <typename T>
void Stack<T>::push(T elem) {
    _data[this->_stackSize] = elem;
    this->_stackSize++;
}

template <typename T>
T Stack<T>::pop() {
    if (this->_isEmpty()) {
        throw StackException(
            "Pop() operation is aborted due to stack is empty.");
    }

    T elem = _data[this->_stackSize - 1];

    _data[_stackSize - 1] = nullptr;
    this->_stackSize--;

    return elem;
}

template <typename T>
T Stack<T>::peek() const {
    if (this->_isEmpty()) {
        throw StackException(
            "Peek() operation is aborted due to stack is empty.");
    }

    T elem = _data[this->_stackSize - 1];

    _data[_stackSize - 1] = nullptr;
    this->_stackSize--;

    return elem;
}

template <typename T>
Stack<T>::~Stack() {
    if (this->_data) {
        delete[] this->_data;
    }
}
