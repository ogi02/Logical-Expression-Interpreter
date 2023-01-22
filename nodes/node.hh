#ifndef LOGICAL_EXPRESSION_INTERPRETER_NODE_HH
#define LOGICAL_EXPRESSION_INTERPRETER_NODE_HH

#include <string>
#include "../enumerations/operator.hh"

using std::string;

class Node {
protected:
    int _value;
    string _string_value;
    Node* _left;
    Node* _right;

public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: Node()
    // Node with value
    //
    // PARAMETERS:
    // none
    //-------------------------------------------------------------------
    Node();

    //-------------------------------------------------------------------
    // GETTER: value()
    // Gets the value of the node
    //-------------------------------------------------------------------
    int value() const;

    //-------------------------------------------------------------------
    // SETTER: set_value()
    // Sets the value of the node
    //
    // PARAMETERS:
    // value (int) -> the value of the node
    //-------------------------------------------------------------------
    void set_value(int value);

    //-------------------------------------------------------------------
    // GETTER: string_value()
    // Gets the string value of the node
    //-------------------------------------------------------------------
    string string_value() const;

    //-------------------------------------------------------------------
    // SETTER: set_string_value()
    // Sets the string value of the node
    //
    // PARAMETERS:
    // string_value (string) -> the string value of the node
    //-------------------------------------------------------------------
    void set_string_value(string string_value);

    //-------------------------------------------------------------------
    // GETTER: left()
    // Gets the left node of the node
    //-------------------------------------------------------------------
    Node* left() const;

    //-------------------------------------------------------------------
    // SETTER: set_left()
    // Sets the left node of the node
    //
    // PARAMETERS:
    // left (Node*) -> the left node of the node
    //-------------------------------------------------------------------
    void set_left(Node* left);

    //-------------------------------------------------------------------
    // GETTER: right()
    // Gets the right node of the node
    //-------------------------------------------------------------------
    Node* right() const;

    //-------------------------------------------------------------------
    // SETTER: set_right()
    // Sets the right node of the node
    //
    // PARAMETERS:
    // right (Node*) -> the right node of the node
    //-------------------------------------------------------------------
    void set_right(Node* right);

    //-------------------------------------------------------------------
    // OPERATOR: =
    // Sets value
    //
    // PARAMETERS:
    // o (const Node&) -> the node that will be assigned
    //
    // RETURNS:
    // (Node&) -> the node that has to be set
    //-------------------------------------------------------------------
    Node& operator=(const Node &o);

    //-------------------------------------------------------------------
    // VIRTUAL FUNCTION: is_calculated()
    // Determines whether a node should be calculated or not depending on the presence of an operator
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (bool)
    //-------------------------------------------------------------------
    virtual bool is_calculated() = 0;

    //-------------------------------------------------------------------
    // VIRTUAL FUNCTION: get_operator()
    // Gets operator from operator node
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (Operator) -> operator as enum value
    //
    // THROWS:
    // std::runtime_error -> when gets called in operand node
    //-------------------------------------------------------------------
    virtual Operator get_operator() = 0;

    //-------------------------------------------------------------------
    // VIRTUAL FUNCTION: get_argument()
    // Gets argument from operand node
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (char) -> argument
    //
    // THROWS:
    // std::runtime_error -> when gets called in operator node
    //-------------------------------------------------------------------
    virtual char get_argument() = 0;
};

#endif //LOGICAL_EXPRESSION_INTERPRETER_NODE_HH
