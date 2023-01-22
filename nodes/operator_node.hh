#ifndef LOGICAL_EXPRESSION_INTERPRETER_OPERATOR_NODE_HH
#define LOGICAL_EXPRESSION_INTERPRETER_OPERATOR_NODE_HH

#include <stdexcept>
using std::runtime_error;

#include "node.hh"
#include "../enumerations/operator.hh"

class OperatorNode : public Node {
private:
    Operator _op;
public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: OperatorNode()
    // Node with operator
    //
    // PARAMETERS:
    // op (char) -> the operator
    //-------------------------------------------------------------------
    OperatorNode(char op);

    //-------------------------------------------------------------------
    // GETTER: op()
    // Gets the value of the operator
    //-------------------------------------------------------------------
    Operator op() const;

    //-------------------------------------------------------------------
    // SETTER: set_operator()
    // Sets the operator of the node
    //
    // PARAMETERS:
    // op (Operator) -> the operator of the node
    //-------------------------------------------------------------------
    void set_operator(Operator op);

    //-------------------------------------------------------------------
    // OPERATOR: =
    // Sets value
    //
    // PARAMETERS:
    // o (const OperatorNode&) -> the operator node that will be assigned
    //
    // RETURNS:
    // (OperatorNode&) -> the operator node that has to be set
    //-------------------------------------------------------------------
    OperatorNode& operator=(const OperatorNode &o);

    //-------------------------------------------------------------------
    // OVERRIDDEN FUNCTION: is_calculated()
    // Determines whether a node should be calculated or not depending on the presence of an operator
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // true
    //-------------------------------------------------------------------
    bool is_calculated() override;

    //-------------------------------------------------------------------
    // OVERRIDDEN FUNCTION: get_operator()
    // Gets operator from operator node
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (Operator) -> operator as enum value
    //-------------------------------------------------------------------
    Operator get_operator() override;

    //-------------------------------------------------------------------
    // OVERRIDDEN FUNCTION: get_argument()
    // Gets argument from operand node
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // none
    //
    // THROWS:
    // std::runtime_error -> when gets called in operator node
    //-------------------------------------------------------------------
    char get_argument() override;
};

#endif //LOGICAL_EXPRESSION_INTERPRETER_OPERATOR_NODE_HH
