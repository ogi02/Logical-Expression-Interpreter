#ifndef LOGICAL_EXPRESSION_INTERPRETER_FUNCTION_HH
#define LOGICAL_EXPRESSION_INTERPRETER_FUNCTION_HH

#include <string>
#include <stdexcept>
#include "vector.hh"
#include "truth_table.hh"
#include "../utils/file_utils.hh"
#include "../utils/string_utils.hh"
#include "../utils/graphics_utils.hh"
#include "../utils/rpn_converter.hh"
#include "../nodes/operand_node.hh"
#include "../nodes/operator_node.hh"
using namespace std;


class Function {
private:
    string _name;
    string _rpn_expression;
    Vector<char> _arguments;
    Node* _expression_tree;
    TruthTable _truth_table;

    // stores functions
    const static string _FILENAME;

    //-------------------------------------------------------------------
    // FUNCTION: _create_tree()
    // Combines the function's name, arguments and expression to
    // a single line in order to be saved in a file
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (string) -> the line for the file
    //-------------------------------------------------------------------
    string _prepare_string_for_file();

    //-------------------------------------------------------------------
    // FUNCTION: _create_tree()
    // Creates a binary tree based on the RPN expression of the function.
    // Sets the root node of the tree to the _expression_tree variable.
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // none
    //-------------------------------------------------------------------
    void _create_tree();

    //-------------------------------------------------------------------
    // FUNCTION: _calculate_node()
    // Calculates a node based on its type.
    // If it is an operand node, it gets the value of this operand based
    // on the parameters given for the solve process.
    // If it is an operator node, the function calls itself for the
    // children nodes.
    //
    // PARAMETERS:
    // node (Node*) -> the node whose value needs to be calculated
    //
    // RETURNS:
    // (int) -> the value of the node
    //-------------------------------------------------------------------
    int _calculate_node(Node* node, Vector<int> params);

    //-------------------------------------------------------------------
    // FUNCTION: _get_argument_index()
    // Gets the index of a given operand in order to apply this index
    // to the parameters collection and get the value of the given operand
    //
    // PARAMETERS:
    // c (char) -> the operand whose index is desired
    //
    // RETURNS:
    // (int) -> the index of the operand
    //-------------------------------------------------------------------
    int _get_argument_index(char c);

public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: Function()
    // Default constructor
    //
    // PARAMETERS:
    // none
    //-------------------------------------------------------------------
    Function();

    //-------------------------------------------------------------------
    // CONSTRUCTOR: Function()
    // Empty vector
    //
    // PARAMETERS:
    // name (string) -> the name of the function
    // rpn_expression (string) -> the expression of the function in RPN
    // arguments (Vector<char>) -> the arguments of the function
    //-------------------------------------------------------------------
    Function(string name, string rpn_expression, Vector<char> arguments);

    //-------------------------------------------------------------------
    // GETTER: name()
    // Gets the name of the function
    //-------------------------------------------------------------------
    string name() const;

    //-------------------------------------------------------------------
    // SETTER: set_name()
    // Sets the name of the function
    //
    // PARAMETERS:
    // name (string) -> the name of the function
    //-------------------------------------------------------------------
    void set_name(string name);

    //-------------------------------------------------------------------
    // GETTER: rpn_expression()
    // Gets the RPN expression of the function
    //-------------------------------------------------------------------
    string rpn_expression() const;

    //-------------------------------------------------------------------
    // SETTER: set_rpn_expression()
    // Sets the RPN expression of the function
    //
    // PARAMETERS:
    // rpn_expression (string) -> the expression of the function in RPN
    //-------------------------------------------------------------------
    void set_rpn_expression(string rpn_expression);

    //-------------------------------------------------------------------
    // GETTER: arguments()
    // Gets the arguments of the function
    //-------------------------------------------------------------------
    Vector<char> arguments() const;

    //-------------------------------------------------------------------
    // SETTER: set_arguments()
    // Sets the arguments of the function
    //
    // PARAMETERS:
    // arguments (Vector<char>) -> the arguments of the function
    //-------------------------------------------------------------------
    void set_arguments(Vector<char> arguments);

    //-------------------------------------------------------------------
    // GETTER: expression_tree()
    // Gets the arguments of the function
    //-------------------------------------------------------------------
    Node* expression_tree() const;

    //-------------------------------------------------------------------
    // SETTER: set_expression_tree()
    // Sets the arguments of the function
    //
    // PARAMETERS:
    // expression_tree (Node*) -> the root of the expression tree
    //-------------------------------------------------------------------
    void set_expression_tree(Node* expression_tree);

    //-------------------------------------------------------------------
    // GETTER: truth_table()
    // Gets the truth table of the function
    //-------------------------------------------------------------------
    TruthTable truth_table() const;

    //-------------------------------------------------------------------
    // SETTER: set_expression_tree()
    // Sets the arguments of the function
    //
    // PARAMETERS:
    // truth_table (TruthTable*) -> the root of the expression tree
    //-------------------------------------------------------------------
    void set_truth_table(TruthTable truth_table);

    //-------------------------------------------------------------------
    // OPERATOR: =
    // Sets value
    //
    // PARAMETERS:
    // o (const Function&) -> the function that will be assigned
    //
    // RETURNS:
    // (Function&) -> the function that has to be set
    //-------------------------------------------------------------------
    Function& operator=(const Function& o);

    //-------------------------------------------------------------------
    // FUNCTION: solve()
    // Solves the function with given parameters.
    // Uses the truth table of the function to check if it has
    // been solved with the given parameters to avoid solving again.
    //
    // PARAMETERS:
    // params (Vector<char>) -> the parameters for the function
    //
    // RETURNS:
    // (int) -> the solution of the function
    //-------------------------------------------------------------------
    int solve(Vector<char> params);
};


#endif //LOGICAL_EXPRESSION_INTERPRETER_FUNCTION_HH
