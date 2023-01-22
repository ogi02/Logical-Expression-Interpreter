#include <utility>

#include "function.hh"

const string Function::_FILENAME = "functions.csv";

Function::Function() { }

Function::Function(std::string name, std::string rpn_expression, Vector<char> arguments) :
    _name(std::move(name)),
    _rpn_expression(std::move(rpn_expression)),
    _arguments(arguments) {
    _create_tree();
    insert_line_in_file(_FILENAME, _prepare_string_for_file());
}

string Function::name() const {
    return _name;
}

void Function::set_name(string name) {
    _name = std::move(name);
}

string Function::rpn_expression() const {
    return _rpn_expression;
}

void Function::set_rpn_expression(string rpn_expression) {
    _rpn_expression = std::move(rpn_expression);
}

Vector<char> Function::arguments() const {
    return _arguments;
}

void Function::set_arguments(Vector<char> arguments) {
    _arguments = arguments;
}

Node* Function::expression_tree() const {
    return _expression_tree;
}

void Function::set_expression_tree(Node* expression_tree) {
    _expression_tree = expression_tree;
}

TruthTable Function::truth_table() const {
    return _truth_table;
}

void Function::set_truth_table(TruthTable truth_table) {
    _truth_table = truth_table;
}

Function& Function::operator=(const Function& o) {
    this->set_name(o.name());
    this->set_arguments(o.arguments());
    this->set_rpn_expression(o.rpn_expression());
    this->set_expression_tree(o.expression_tree());
    this->set_truth_table(o.truth_table());
    return *this;
}

int Function::solve(Vector<char> params) {
    // check if function is already solved with these parameters
    int tried = _truth_table.get(params.to_string());
    if (tried != -1) {
        return tried;
    }

    // convert parameters to int
    Vector<int> p;
    for (int i = 0; i < params.size(); i++) {
        char c = params[i];
        switch (c) {
            case '0':
                p.push_back(0);
                break;
            case '1':
                p.push_back(1);
                break;
            default:
                // cast to string so that it can be appended to error
                string arg = string(1, c);
                string error = "Invalid argument in solve command - expected 0 or 1, found " + arg;
                throw invalid_argument(error);
        }
    }

    // solve and update truth table
    int result = _calculate_node(expression_tree(), p);
    _truth_table.update(params.to_string(), result);

    // visualize solution
    draw_tree(expression_tree());

    return result;
}

string Function::_prepare_string_for_file() {
    return name() + "," + arguments().to_string() + "," + rpn_expression();
}

void Function::_create_tree() {
    // temporary vector for storing operands and operators
    Vector<Node*> node_vector;

    for (int i = 0; i < get_length((string &) _rpn_expression); i++) {
        if (is_operator(_rpn_expression[i])) {
            // operators get pushed with the top 2 elements in temp as left and right nodes
            Node* temp = new OperatorNode(_rpn_expression[i]);
            if (_rpn_expression[i] == '!') {
                // operator "NOT" is unary
                temp->set_left(node_vector.pop());
            } else {
                // operators "AND" and "OR" are binary
                temp->set_right(node_vector.pop());
                temp->set_left(node_vector.pop());
            }
            node_vector.push_back(temp);
        } else {
            // operands get directly pushed in the temporary vector to become branches of the tree
            node_vector.push_back(new OperandNode(_rpn_expression[i]));
        }
    }
    set_expression_tree(node_vector.top());

    // visualize expression tree
    draw_tree(expression_tree());
}

int Function::_get_argument_index(char c) {
    for (int i = 0; i < _arguments.size(); i++) {
        if (_arguments[i] == c) {
            return i;
        }
    }
    return -1;
}

int Function::_calculate_node(Node* node, Vector<int> params) {
    int res;
    if (!node->is_calculated()) {
        int left, right;
        string new_string_value;
        // operator node
        switch (node->get_operator()) {
            case Operator::AND: {
                left = _calculate_node(node->left(), params);
                right = _calculate_node(node->right(), params);
                res = left & right;
                new_string_value = to_string(left) + "&" + to_string(right) + "=" + to_string(res);
                break;
            }
            case Operator::OR: {
                left = _calculate_node(node->left(), params);
                right = _calculate_node(node->right(), params);
                res = left | right;
                new_string_value = to_string(left) + "|" + to_string(right) + "=" + to_string(res);
                break;
            }
            case Operator::NOT: {
                left = _calculate_node(node->left(), params);
                res = !left;
                new_string_value = "!" + to_string(left) + "=" + to_string(res);
                break;
            }
        }
        node->set_string_value(new_string_value);
    } else {
        // operand node
        res = params[_get_argument_index(node->get_argument())];
        node->set_string_value(to_string(res));
    }
    return res;
}
