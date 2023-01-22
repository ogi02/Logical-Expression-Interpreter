#include "truth_table.hh"

TruthTable::TruthTable() : _size(0) {
    _keys = Vector<string>();
    _values = Vector<int>();
}

int TruthTable::size() const {
    return _size;
}

void TruthTable::set_size(int size) {
    _size = size;
}

Vector<string> TruthTable::keys() const {
    return _keys;
}

void TruthTable::set_keys(Vector<string> keys) {
    _keys = keys;
}

Vector<int> TruthTable::values() const {
    return _values;
}

void TruthTable::set_values(Vector<int> values) {
    _values = values;
}

TruthTable& TruthTable::operator=(const TruthTable& o) {
    this->set_size(o.size());
    this->set_keys(o.keys());
    this->set_values(o.values());
    return *this;
}

void TruthTable::update(string key, int value) {
    // get index of key if it exists
    int index = _keys.get_index_of(key);
    if (index == -1) {
        // key is not present
        _keys.push_back(key);
        _values.push_back(value);
        _size++;
    } else {
        // key is present
        _values[index] = value;
    }
}

int TruthTable::get(string key) {
    int index = _keys.get_index_of(key);
    if (index == -1) {
        // doesn't exist
        return -1;
    }
    // exists
    return _values[index];
}