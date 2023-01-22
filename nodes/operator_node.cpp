#include "operator_node.hh"

OperatorNode::OperatorNode(char op) : Node() {
    this->set_string_value(string(1, op));
    if (op == '&') {
        this->set_operator(Operator::AND);
    } else if (op == '|') {
        this->set_operator(Operator::OR);
    } else if (op == '!') {
        this->set_operator(Operator::NOT);
    }
}

Operator OperatorNode::op() const {
    return _op;
}

void OperatorNode::set_operator(Operator op) {
    _op = op;
}

OperatorNode& OperatorNode::operator=(const OperatorNode &o) {
    this->set_value(o.value());
    this->set_string_value(o.string_value());
    this->set_operator(o.op());
    this->set_left(o.left());
    this->set_right(o.right());
    return *this;
}

bool OperatorNode::is_calculated() {
    return false;
}

Operator OperatorNode::get_operator() {
    return op();
}

char OperatorNode::get_argument() {
    throw runtime_error("Operator nodes have no arguments!");
}
