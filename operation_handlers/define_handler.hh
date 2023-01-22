#ifndef LOGICAL_EXPRESSION_INTERPRETER_DEFINE_HANDLER_HH
#define LOGICAL_EXPRESSION_INTERPRETER_DEFINE_HANDLER_HH

#include <string>
#include <iostream>
#include <stdexcept>
#include "../data_types/function.hh"
#include "../data_types/queue.hh"
#include "../utils/string_utils.hh"
#include "../utils/rpn_converter.hh"
using namespace std;

//-------------------------------------------------------------------
// FUNCTION: get_function_declaration()
// Gets the function declaration from the whole definition
// This includes function name and arguments
//
// PARAMETERS:
// definition (string&) -> the definition of the function
//
// RETURNS:
// (string) -> the function declaration
//-------------------------------------------------------------------
string get_function_declaration(string &definition);

//-------------------------------------------------------------------
// FUNCTION: get_function_name_for_define()
// Gets the function name from the function declaration
//
// PARAMETERS:
// func_decl (string&) -> the declaration of the function
// existing_function (Queue<Function>) -> existing functions to check there are no name duplicates
//
// RETURNS:
// (string) -> the function name
//-------------------------------------------------------------------
string get_function_name_for_define(string &func_decl, Queue<Function> existing_functions);

//-------------------------------------------------------------------
// FUNCTION: get_function_arguments_for_define()
// Gets the function arguments from the function declaration
//
// PARAMETERS:
// func_decl (string&) -> the declaration of the function
//
// RETURNS:
// (string) -> the function arguments
//-------------------------------------------------------------------
string get_function_arguments_for_define(string &func_decl);

//-------------------------------------------------------------------
// FUNCTION: get_function_expression()
// Gets the function expression from the whole definition
// Converts to RPN if not already
//
// PARAMETERS:
// expression (string&) -> the expression as it was split from the function declaration
// arguments (Vector<char>) -> the possible arguments in the expression
// existing_functions (Queue<Function>) -> existing functions that may be used in expression
//
// RETURNS:
// (Vector<char>) -> the function expression in RPN
//-------------------------------------------------------------------
Vector<char> get_function_expression(string &expression, Vector<char> arguments, Queue<Function> existing_functions);

//-------------------------------------------------------------------
// FUNCTION: validate_function_in_expression()
// Validate that the functions used in the expression of the define command exists
// Checks by name and argument count
//
// PARAMETERS:
// expression (string&) -> the function expression
// begin (int) -> the index at which the used function begins
// existing_functions (Queue<Function>) -> existing functions to compare
//
// RETURNS:
// (Function) -> the function if it exists
//
// THROWS:
// std::runtime_error -> if the function doesn't exist
//-------------------------------------------------------------------
Function validate_function_in_expression(string &expression, int begin, Queue<Function> existing_functions);

//-------------------------------------------------------------------
// FUNCTION: process_define()
// Processes the whole define process. Extracts function name and arguments,
// converts the expression to RPN if needed, check for errors throughout the process
//
// PARAMETERS:
// definition (string&) -> the function definition
// existing_functions (Queue<Function>) -> existing functions that may be used in expression
//
// RETURNS:
// (Function) -> the function with its name, arguments, RPN expression and RPN tree
//-------------------------------------------------------------------
Function process_define(string &definition, Queue<Function> existing_functions);

#endif //LOGICAL_EXPRESSION_INTERPRETER_DEFINE_HANDLER_HH