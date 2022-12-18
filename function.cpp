#include <utility>

#include "function.hh"

Function::Function(std::string name, std::string rpn_expression, Vector<string> arguments) :
    _name(std::move(name)),
    _rpn_expression(std::move(rpn_expression)),
    _arguments(arguments) { }

string Function::name() const {
    return _name;
}

string Function::rpn_expression() const {
    return _rpn_expression;
};

Vector<string> Function::arguments() const {
    return _arguments;
}
