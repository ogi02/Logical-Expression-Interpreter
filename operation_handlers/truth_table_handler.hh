#ifndef LOGICAL_EXPRESSION_INTERPRETER_TRUTH_TABLE_HANDLER_HH
#define LOGICAL_EXPRESSION_INTERPRETER_TRUTH_TABLE_HANDLER_HH

#include "../data_types/vector.hh"
#include "../data_types/queue.hh"
#include "../data_types/function.hh"
#include "../utils/string_utils.hh"
#include <math.h>

//-------------------------------------------------------------------
// FUNCTION: generate_truth_table()
// Recursively creates every combination of arguments and solves
// the given function with them saving the answers in its truth table
//
// PARAMETERS:
// function (Function) -> the function which will be solved
// argument_count (int) -> count of function arguments (used to stop recursion)
// params (char[]) -> stores the current combination of arguments
// curr_argument (int) -> count of arguments in param (used to stop recursion)
//
// RETURNS:
// none
//-------------------------------------------------------------------
void generate_truth_table(Function function, int argument_count, char params[], int curr_argument);

//-------------------------------------------------------------------
// FUNCTION: process_all()
// Processes all command and generates a truth table for a given
// function if it exists. Compares by function name
//
// PARAMETERS:
// line (string&) -> the all command
// functions (Queue<Function>) -> existing functions to compare
//
// RETURNS:
// none
//
// THROWS:
// std::runtime_error -> if the function doesn't exist
//-------------------------------------------------------------------
void process_all(string &line, Queue<Function> functions);

#endif //LOGICAL_EXPRESSION_INTERPRETER_TRUTH_TABLE_HANDLER_HH
