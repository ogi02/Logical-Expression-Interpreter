#ifndef LOGICAL_EXPRESSION_INTERPRETER_FUNCTION_HH
#define LOGICAL_EXPRESSION_INTERPRETER_FUNCTION_HH

#include <string>
#include "vector.hh"
using std::string;

class Function {
private:
    const string _name;
    const string _rpn_expression;
    const Vector<string> _arguments;
public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: Function()
    // Empty vector
    //
    // PARAMETERS:
    // name (string) -> the name of the function
    // rpn_expression (string) -> the expression of the function in RPN
    // arguments (Vector<string>) -> the arguments of the function
    //-------------------------------------------------------------------
    Function(string name, string rpn_expression, Vector<string> arguments);

    //-------------------------------------------------------------------
    // GETTER: name()
    // Gets the name of the function
    //-------------------------------------------------------------------
    string name() const;

    //-------------------------------------------------------------------
    // GETTER: rpn_expression()
    // Gets the RPN expression of the function
    //-------------------------------------------------------------------
    string rpn_expression() const;

    //-------------------------------------------------------------------
    // GETTER: arguments()
    // Gets the arguments of the function
    //-------------------------------------------------------------------
    Vector<string> arguments() const;
};


#endif //LOGICAL_EXPRESSION_INTERPRETER_FUNCTION_HH
