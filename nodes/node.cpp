#include "node.hh"

Node::Node() {
    _left = nullptr;
    _right = nullptr;
}

int Node::value() const {
    return _value;
}

void Node::set_value(int value) {
    _value = value;
}

string Node::string_value() const {
    return _string_value;
}

void Node::set_string_value(string string_value) {
    _string_value = string_value;
}

Node* Node::left() const {
    return _left;
}

void Node::set_left(Node *left) {
    _left = left;
}

Node* Node::right() const {
    return _right;
}

void Node::set_right(Node *right) {
    _right = right;
}


Node& Node::operator=(const Node &o) {
    this->set_value(o.value());
    this->set_left(o.left());
    this->set_right(o.right());
    return *this;
}
