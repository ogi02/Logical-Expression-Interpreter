#ifndef LOGICAL_EXPRESSION_INTERPRETER_RPN_CONVERTER_HH
#define LOGICAL_EXPRESSION_INTERPRETER_RPN_CONVERTER_HH
#include <string>
#include <iostream>
#include "vector.hh"
#include "string_utils.hh"
using std::string;

//-------------------------------------------------------------------
// FUNCTION: is_opening_bracket()
//
// PARAMETERS:
// c (char) -> character to be checked
//
// RETURNS:
// (bool)
//-------------------------------------------------------------------
bool is_opening_bracket(char c);

//-------------------------------------------------------------------
// FUNCTION: is_closing_bracket()
//
// PARAMETERS:
// c (char) -> character to be checked
//
// RETURNS:
// (bool)
//-------------------------------------------------------------------
bool is_closing_bracket(char c);

//-------------------------------------------------------------------
// FUNCTION: is_operator()
// Checks if a character is an operator in the boolean algebra
// Valid operators -> "!", "&", "|"
//
// PARAMETERS:
// c (char) -> character to be checked
//
// RETURNS:
// (bool)
//-------------------------------------------------------------------
bool is_operator(char c);

//-------------------------------------------------------------------
// FUNCTION: is_operand()
// Checks if a character is a valid operand
// This includes small letters and capital letters
//
// PARAMETERS:
// c (char) -> character to be checked
//
// RETURNS:
// (bool)
//-------------------------------------------------------------------
bool is_operand(char c);

//-------------------------------------------------------------------
// FUNCTION: precedence()
// Gets precedence of a character
// Precedence in boolean algebra: ! -> & -> | -> everything else
// Operator "!" has a precedence of 3
// Operator "&" has a precedence of 2
// Operator "|" has a precedence of 1
// Everything else has a precedence of 0
//
// PARAMETERS:
// op (char) -> the character whose precedence must be figured out
//
// RETURNS:
// (int) -> the precedence value
//-------------------------------------------------------------------
int precedence(char op);

//-------------------------------------------------------------------
// FUNCTION: compare_precedence()
// Compares precedence between two operators
//
// PARAMETERS:
// op1 (char) -> first character in the comparison
// op2 (char) -> second character in the comparison
//
// RETURNS:
// (int)
// -1 if precedence(op1) <  precedence(op2)
// 0  if precedence(op1) == precedence(op2)
// 1  if precedence(op1) >  precedence(op2)
//-------------------------------------------------------------------
int compare_precedence(char op1, char op2);

//-------------------------------------------------------------------
// FUNCTION: convert_to_rpn
// Convert an infix expression to RPN (postfix) expression
// RPN -> reverse polish notation
//
// PARAMETERS:
// infix (string) -> the expression in infix format
//
// RETURNS:
// (Vector<char>) -> vector with the RPN expression
//-------------------------------------------------------------------
Vector<char> convert_to_rpn(string infix);

#endif //LOGICAL_EXPRESSION_INTERPRETER_RPN_CONVERTER_HH
