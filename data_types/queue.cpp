#include "queue.hh"

template <typename Object>
Queue<Object>::Queue(int cap) : _capacity(cap), _objects(new Object[cap]) { }

template <typename Object>
int Queue<Object>::size() const {
    return _size;
}

template <typename Object>
Object& Queue<Object>::operator[](int index) const {
    return _objects[index];
}

template <typename Object>
Object Queue<Object>::first() const {
    return _objects[0];
}

template <typename Object>
bool Queue<Object>::is_empty() {
    return _size == 0;
}

template <>
Function& Queue<Function>::get(string function_name, int argument_count) {
    for (int i = 0; i < _size; i++) {
        if (_objects[i].name() == function_name && _objects[i].arguments().size() == argument_count) {
            return _objects[i];
        }
    }

    string error = "No definition exists for function " + function_name +
        " that takes " + to_string(argument_count) + " arguments!";
    throw runtime_error(error);
}

template <>
Function& Queue<Function>::get_by_function_name(string function_name) {
    for (int i = 0; i < _size; i++) {
        if (_objects[i].name() == function_name) {
            return _objects[i];
        }
    }

    string error = "No definition exists for function \"" + function_name + "\"!";
    throw runtime_error(error);
}

template <typename Object>
void Queue<Object>::enqueue(const Object& o) {
    if (_size == _capacity) {
        // + 1 for the beginning when both size and capacity are 0
        expand(_capacity * 2 + 1);
    }
    _objects[_size++] = o;
}

template <typename Object>
void Queue<Object>::expand(int new_capacity) {
    if (new_capacity < _size) {
        // if array is already large enough, return
        return;
    }

    // create and fill new array
    auto *new_objects = new Object[new_capacity];
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
Object Queue<Object>::dequeue() {
    // get first object
    Object first = _objects[0];
    // move all objects on index back
    for (int i = 1; i < _size; i++) {
        _objects[i - 1] = _objects[i];
    }
    _size--;
    // return first object
    return first;
}

template class Queue<string>;
template class Queue<Function>;
template class Queue<Implicant>;
