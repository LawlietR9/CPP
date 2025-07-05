#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &src) {
    _array = new T[src.size()];
    _size = src.size();
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = src._array[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs) {
    if (this != &rhs) {
        delete[] _array;
        _array = new T[rhs.size()];
        _size = rhs.size();
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = rhs._array[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw std::exception();
    }
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}
