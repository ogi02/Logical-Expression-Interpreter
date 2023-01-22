#ifndef LOGICAL_EXPRESSION_INTERPRETER_SOLVE_HANDLER_HH
#define LOGICAL_EXPRESSION_INTERPRETER_SOLVE_HANDLER_HH

#include <string>
#include "../data_types/queue.hh"
#include "../data_types/function.hh"
using std::string;

//-------------------------------------------------------------------
// FUNCTION: get_function_name_for_solve()
// Gets the function name from the solve command
//
// PARAMETERS:
// command (string&) -> the solve command
//
// RETURNS:
// (string) -> the function name
//-------------------------------------------------------------------
string get_function_name_for_solve(string &command);

//-------------------------------------------------------------------
// FUNCTION: get_function_arguments_for_solve()
// Gets the function arguments from the solve command
//
// PARAMETERS:
// command (string&) -> the solve command
//
// RETURNS:
// (string) -> the function arguments
//-------------------------------------------------------------------
string get_function_arguments_for_solve(string &command);

//-------------------------------------------------------------------
// FUNCTION: process_solve()
// Processes the solve command and solves the function with given arguments
// Compares with existing functions by name and argument count
//
// PARAMETERS:
// line (string&) -> the solve command
// functions (Queue<Function>&) -> the existing functions
//
// RETURNS:
// none
//
// THROWS:
// std::runtime_error -> if the function doesn't exist
//-------------------------------------------------------------------
void process_solve(string &line, Queue<Function> &functions);

#endif //LOGICAL_EXPRESSION_INTERPRETER_SOLVE_HANDLER_HH
