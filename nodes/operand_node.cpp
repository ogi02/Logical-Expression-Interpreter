#include "operand_node.hh"

OperandNode::OperandNode(char argument) : Node() {
    this->_argument = argument;
    this->set_string_value(string(1, _argument));
}

char OperandNode::argument() const {
    return _argument;
}

void OperandNode::set_argument(char argument) {
    _argument = argument;
}

OperandNode& OperandNode::operator=(const OperandNode &o) {
    this->set_value(o.value());
    this->set_string_value(o.string_value());
    this->set_argument(o.argument());
    this->set_left(o.left());
    this->set_right(o.right());
    return *this;
}

bool OperandNode::is_calculated() {
    return true;
}

Operator OperandNode::get_operator() {
    throw runtime_error("Operand nodes have no operators!");
}

char OperandNode::get_argument() {
    return argument();
}

