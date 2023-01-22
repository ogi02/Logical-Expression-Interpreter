#ifndef LOGICAL_EXPRESSION_INTERPRETER_OPERAND_NODE_HH
#define LOGICAL_EXPRESSION_INTERPRETER_OPERAND_NODE_HH

#include "node.hh"
#include "../enumerations/operator.hh"
#include <stdexcept>
using std::runtime_error;

class OperandNode : public Node {
private:
    char _argument = '\0';

public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: OperandNode()
    // Node with operand
    //
    // PARAMETERS:
    // argument (char) -> the operand
    //-------------------------------------------------------------------
    OperandNode(char argument);

    //-------------------------------------------------------------------
    // GETTER: argument()
    // Gets the operand
    //-------------------------------------------------------------------
    char argument() const;

    //-------------------------------------------------------------------
    // SETTER: set_argument()
    // Sets the operand of the node
    //
    // PARAMETERS:
    // argument (char) -> the operand of the node
    //-------------------------------------------------------------------
    void set_argument(char argument);

    //-------------------------------------------------------------------
    // OPERATOR: =
    // Sets value
    //
    // PARAMETERS:
    // o (const OperandNode&) -> the operand node that will be assigned
    //
    // RETURNS:
    // (OperandNode&) -> the operand node that has to be set
    //-------------------------------------------------------------------
    OperandNode& operator=(const OperandNode &o);

    //-------------------------------------------------------------------
    // OVERRIDDEN FUNCTION: is_calculated()
    // Determines whether a node should be calculated or not depending on the presence of an operator
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // false
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
    // none
    //
    // THROWS:
    // std::runtime_error -> when gets called in operand node
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
    // (char) -> the argument
    //-------------------------------------------------------------------
    char get_argument() override;
};

#endif //LOGICAL_EXPRESSION_INTERPRETER_OPERAND_NODE_HH
