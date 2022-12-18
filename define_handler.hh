#ifndef LOGICAL_EXPRESSION_INTERPRETER_DEFINE_HANDLER_HH
#define LOGICAL_EXPRESSION_INTERPRETER_DEFINE_HANDLER_HH

#include <string>
#include <iostream>
#include <stdexcept>
#include "function.hh"
#include "string_utils.hh"
#include "rpn_converter.hh"
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
// FUNCTION: get_function_name()
// Gets the function name from the function declaration
//
// PARAMETERS:
// func_decl (string&) -> the declaration of the function
//
// RETURNS:
// (string) -> the function name
//-------------------------------------------------------------------
string get_function_name(string &func_decl);

//-------------------------------------------------------------------
// FUNCTION: get_function_arguments()
// Gets the function arguments from the function declaration
//
// PARAMETERS:
// func_decl (string&) -> the declaration of the function
//
// RETURNS:
// (string) -> the function arguments
//-------------------------------------------------------------------
string get_function_arguments(string &func_decl);

//-------------------------------------------------------------------
// FUNCTION: get_function_expression()
// Gets the function expression from the whole definition
// Converts to RPN if not already
//
// PARAMETERS:
// expression (string&) -> the expression as it was split from the function declaration
//
// RETURNS:
// (Vector<char>) -> the function expression in RPN
//-------------------------------------------------------------------
Vector<char> get_function_expression(string &expression);

Function process_define(string &definition, int len);

#endif //LOGICAL_EXPRESSION_INTERPRETER_DEFINE_HANDLER_HH