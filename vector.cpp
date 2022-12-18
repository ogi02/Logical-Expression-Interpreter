#include <string>
#include "vector.hh"

template <typename Object>
Vector<Object>::Vector(int len) : _size(0), _capacity(len), _objects(new Object[len]) { }

template <>
Vector<char>::Vector(string from, int len) : _size(len), _capacity(len), _objects(new char[len]) {
    for (int i = 0; i < len; i++) {
        _objects[i] = from[i];
    }
}

template <typename Object>
Object& Vector<Object>::operator[] (int index) const {
    return _objects[index];
}

template <typename Object>
int Vector<Object>::size() const {
    return _size;
}

template <typename Object>
Object Vector<Object>::top() const {
    return _objects[_size - 1];
}

template <typename Object>
bool Vector<Object>::is_empty() {
    return _size == 0;
}

template <typename Object>
void Vector<Object>::push_back(const Object& o) {
    if (_size == _capacity) {
        // + 1 for the beginning when both size and capacity are 0
        expand(_capacity * 2 + 1);
    }
    _objects[_size++] = o;
}

template <typename Object>
void Vector<Object>::expand(int new_capacity) {
    if (new_capacity < _size) {
        // if array is already large enough, return
        return;
    }

    // create and fill new array
    Object *new_objects = new Object[new_capacity];
    for (int i = 0; i < _size; i++) {
        new_objects[i] = _objects[i];
    }

    // swap pointers to arrays
    std::swap(_objects, new_objects);
    // set new capacity
    _capacity = new_capacity;
    // delete the original array
    delete [] new_objects;
}

template <typename Object>
Object Vector<Object>::pop() {
    return _objects[--_size];
}

template <>
string Vector<char>::to_string() {
    // only for char
    string res = "";
    for (int i = 0; i < _size; i++) {
        res += _objects[i];
    }

    return res;
}

template class Vector<char>;
template class Vector<std::string>;
