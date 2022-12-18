#ifndef LOGICAL_EXPRESSION_INTERPRETER_STRING_UTILS_HH
#define LOGICAL_EXPRESSION_INTERPRETER_STRING_UTILS_HH

#include <string>
#include <stdexcept>
#include "vector.hh"
#include "command.hh"
using namespace std;

//-------------------------------------------------------------------
// FUNCTION: get_length()
// Gets length of a given string
//
// PARAMETERS:
// str (string&) -> the string whose length is desired
//
// RETURNS:
// (int) -> length of the string
//-------------------------------------------------------------------
int get_length(string &str);

//-------------------------------------------------------------------
// FUNCTION: count_chars()
// Counts number of occurrence of a given character in a string
//
// PARAMETERS:
// c (char) -> the character whose count is desired
// str (string&) -> the string which will be searched
// len (int) -> the length of the string
//
// RETURNS:
// (int) -> number of occurrence of the given character
//-------------------------------------------------------------------
int count_chars(char c, string &str, int len);

//-------------------------------------------------------------------
// FUNCTION: find_first()
// Finds the first occurrence of a given character in a string
// Returns -1 if the character was not found in the string
//
// PARAMETERS:
// c (char) -> the character whose first occurrence is desired
// str (string&) -> the string which will be searched
// len (int) -> the length of the string
//
// RETURNS:
// (int) -> length of the string
//-------------------------------------------------------------------
int find_first(char c, string &str, int len);

//-------------------------------------------------------------------
// FUNCTION: remove_char_at_index()
// Removed character in a string at a given index
// Returns -1 if the index is out of bounds
//
// PARAMETERS:
// index (int) -> the index at which the character will be removed
// str (string&) -> the string which will be searched
// len (int) -> the length of the string
//
// RETURNS:
// 0 (int) -> on success
// -1 (int) -> on fail
//-------------------------------------------------------------------
int remove_char_at_index(int index, string &str, int len);

//-------------------------------------------------------------------
// FUNCTION: remove_all_chars()
// Removes every occurrence of a given character in a string
//
// PARAMETERS:
// c (char) -> the character which must be removed
// str (string&) -> the string which will be searched
// len (int&) -> the length of the string
//
// RETURNS:
// void
//-------------------------------------------------------------------
void remove_all_chars(char c, string &str, int &len);

//-------------------------------------------------------------------
// FUNCTION: replace_char_at_index()
// Replaces a character into a given index in a string
// Returns -1 if index is out of bounds
//
// PARAMETERS:
// index (int) -> the index where the replacement will happen
// c (char) -> the character which will go in the string
// str (string&) -> the string which will be modified
// len (int) -> the length of the string
//
// RETURNS:
// 0 (int) -> on success
// -1 (int) -> on fail
//-------------------------------------------------------------------
int replace_char_at_index(int index, char c, string &str, int len);

//-------------------------------------------------------------------
// FUNCTION: trim_spaces()
// Trims excessive spaces in the beginning, end and middle
//
// PARAMETERS:
// str (string&) -> the string which will be trimmed
// len (int&) -> the length of the string
//
// RETURNS:
// void
//-------------------------------------------------------------------
void trim_spaces(string &str, int &len);

//-------------------------------------------------------------------
// FUNCTION: trim_leading_spaces()
// Removes every space in the beginning of the string
//
// PARAMETERS:
// str (string&) -> the string which will be trimmed
// len (int&) -> the length of the string
//
// RETURNS:
// void
//-------------------------------------------------------------------
void trim_leading_spaces(string &str, int &len);

//-------------------------------------------------------------------
// FUNCTION: trim_trailing_spaces()
// Removes every space in the end of the string
//
// PARAMETERS:
// str (string&) -> the string which will be trimmed
// len (int&) -> the length of the string
//
// RETURNS:
// void
//-------------------------------------------------------------------
void trim_trailing_spaces(string &str, int &len);

//-------------------------------------------------------------------
// FUNCTION: trim_duplicate_spaces()
// Removes every duplicate space in the middle of the string
//
// PARAMETERS:
// str (string&) -> the string which will be trimmed
// len (int&) -> the length of the string
//
// RETURNS:
// void
//-------------------------------------------------------------------
void trim_duplicate_spaces(string &str, int &len);

//-------------------------------------------------------------------
// FUNCTION: split_string()
// Splits string at every separator
//
// PARAMETERS:
// separator (char) -> separator at which the string will be split
// str (string&) -> the string which will be trimmed
// len (int) -> the length of the string
//
// RETURNS:
// (Vector<string>) -> the vector with the separated strings
//
// THROWS:
// std::runtime_error -> when separator is not in the string
//-------------------------------------------------------------------
Vector<string> split_string(char separator, string &str, int len);

//-------------------------------------------------------------------
// FUNCTION: split_string_at_index_return_first()
// Splits a string at a given index
// Returns first part, removes it from the reference of the string
//
// PARAMETERS:
// index (int) -> the index at which the string will be split
// str (string&) -> the string which will be trimmed
// len (int) -> the length of the string
//
// RETURNS:
// (string) -> the part before the index
//-------------------------------------------------------------------
string split_string_at_index_return_first(int index, string &str, int len);

//-------------------------------------------------------------------
// FUNCTION: get_command_from_string()
// Casts string to Command enumeration
//
// PARAMETERS:
// command (string&) -> the command
//
// RETURNS:
// (Command) -> the command as enum type
//
// THROWS:
// std::runtime_error -> when the string command doesn't exist in the enum
//-------------------------------------------------------------------
Command get_command_from_string(string &command);

#endif //LOGICAL_EXPRESSION_INTERPRETER_STRING_UTILS_HH
