#ifndef LOGICAL_EXPRESSION_INTERPRETER_STRING_UTILS_HH
#define LOGICAL_EXPRESSION_INTERPRETER_STRING_UTILS_HH

#include <string>
#include <stdexcept>

#include "../data_types/vector.hh"
#include "../enumerations/command.hh"

using namespace std;

//-------------------------------------------------------------------
// FUNCTION: is_letter()
// Check if a character is a letter
//
// PARAMETERS:
// c (char) -> the character which will be checked
//
// RETURNS:
// (bool) -> letter or not
//-------------------------------------------------------------------
bool is_letter(char c);

//-------------------------------------------------------------------
// FUNCTION: is_digit()
// Check if a character is a digit
//
// PARAMETERS:
// c (char) -> the character which will be checked
//
// RETURNS:
// (bool) -> digit or not
//-------------------------------------------------------------------
bool is_digit(char c);

//-------------------------------------------------------------------
// FUNCTION: is_letter_or_digit()
// Check if a character is a letter or digit
//
// PARAMETERS:
// c (char) -> the character which will be checked
//
// RETURNS:
// (bool) -> letter/digit or not
//-------------------------------------------------------------------
bool is_letter_or_digit(char c);

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
//
// RETURNS:
// (int) -> number of occurrence of the given character
//-------------------------------------------------------------------
int count_chars(char c, string &str);

//-------------------------------------------------------------------
// FUNCTION: find_first()
// Finds the first occurrence of a given character in a string
// Returns -1 if the character was not found in the string
//
// PARAMETERS:
// c (char) -> the character whose first occurrence is desired
// str (string&) -> the string which will be searched
//
// RETURNS:
// (int) -> the first occurrence
//-------------------------------------------------------------------
int find_first(char c, string &str);

//-------------------------------------------------------------------
// FUNCTION: remove_char_at_index()
// Removed character in a string at a given index
// Returns -1 if the index is out of bounds
//
// PARAMETERS:
// index (int) -> the index at which the character will be removed
// str (string&) -> the string which will be searched
//
// RETURNS:
// 0 (int) -> on success
// -1 (int) -> on fail
//-------------------------------------------------------------------
int remove_char_at_index(int index, string &str);

//-------------------------------------------------------------------
// FUNCTION: remove_all_chars()
// Removes every occurrence of a given character in a string
//
// PARAMETERS:
// c (char) -> the character which must be removed
// str (string&) -> the string which will be searched
//
// RETURNS:
// void
//-------------------------------------------------------------------
void remove_all_chars(char c, string &str);

//-------------------------------------------------------------------
// FUNCTION: replace_char_at_index()
// Replaces a character into a given index in a string
// Returns -1 if index is out of bounds
//
// PARAMETERS:
// index (int) -> the index where the replacement will happen
// c (char) -> the character which will go in the string
// str (string&) -> the string which will be modified
//
// RETURNS:
// 0 (int) -> on success
// -1 (int) -> on fail
//
// THROWS:
// std::runtime_error -> when index is out of bounds
//-------------------------------------------------------------------
int replace_char_at_index(int index, char c, string &str);

//-------------------------------------------------------------------
// FUNCTION: trim_spaces()
// Trims excessive spaces in the beginning, end and middle
//
// PARAMETERS:
// str (string&) -> the string which will be trimmed
//
// RETURNS:
// void
//-------------------------------------------------------------------
void trim_spaces(string &str);

//-------------------------------------------------------------------
// FUNCTION: trim_leading_spaces()
// Removes every space in the beginning of the string
//
// PARAMETERS:
// str (string&) -> the string which will be trimmed
//
// RETURNS:
// void
//-------------------------------------------------------------------
void trim_leading_spaces(string &str);

//-------------------------------------------------------------------
// FUNCTION: trim_trailing_spaces()
// Removes every space in the end of the string
//
// PARAMETERS:
// str (string&) -> the string which will be trimmed
//
// RETURNS:
// void
//-------------------------------------------------------------------
void trim_trailing_spaces(string &str);

//-------------------------------------------------------------------
// FUNCTION: trim_duplicate_spaces()
// Removes every duplicate space in the middle of the string
//
// PARAMETERS:
// str (string&) -> the string which will be trimmed
//
// RETURNS:
// void
//-------------------------------------------------------------------
void trim_duplicate_spaces(string &str);

//-------------------------------------------------------------------
// FUNCTION: split_string_to_chars()
// Splits string into characters at every separator
//
// PARAMETERS:
// separator (char) -> separator at which the string will be split
// str (string&) -> the string which will be split
//
// RETURNS:
// (Vector<char>) -> the vector with the separated characters
//
// THROWS:
// std::invalid_argument -> when separator is not in the string
// std::invalid_argument -> when an element is not a character
//-------------------------------------------------------------------
Vector<char> split_string_to_chars(char separator, string &str);

//-------------------------------------------------------------------
// FUNCTION: split_string_to_strings()
// Splits string into characters at every separator
//
// PARAMETERS:
// separator (char) -> separator at which the string will be split
// str (string&) -> the string which will be split
//
// RETURNS:
// (Vector<string>) -> the vector with the separated strings
//
// THROWS:
// std::invalid_argument -> when separator is not in the string
//-------------------------------------------------------------------
Vector<string> split_string_to_strings(char separator, string &str);

//-------------------------------------------------------------------
// FUNCTION: split_string_at_index_return_first()
// Splits a string at a given index
// Returns first part, removes it from the reference of the string
//
// PARAMETERS:
// index (int) -> the index at which the string will be split
// str (string&) -> the string which will be trimmed
//
// RETURNS:
// (string) -> the part before the index
//
// THROWS:
// std::invalid_argument -> when index is out of bounds
//-------------------------------------------------------------------
string split_string_at_index_return_first(int index, string &str);

//-------------------------------------------------------------------
// FUNCTION: add_substring_to_string()
// Adds substring to string at a given index
//
// PARAMETERS:
// index (int) -> the index at which substring will be inserted
// str (string&) -> the original string
// substr (string) -> the substring
//
// RETURNS:
// none
//-------------------------------------------------------------------
void add_substring_to_string(int index, string &str, string substr);

//-------------------------------------------------------------------
// FUNCTION: remove_substring_from_string()
// Removes the part of the string between two indexes
//
// PARAMETERS:
// begin (int) -> the starting index
// end (int) -> the index at the end
// str (string&) -> the string which will be trimmed
//
// RETURNS:
// none
//
// THROWS:
// std::invalid_argument -> when index is out of bounds
// std::invalid_argument -> when begin index is greater than end index
//-------------------------------------------------------------------
void remove_substring_from_string(int begin, int end, string &str);

//-------------------------------------------------------------------
// FUNCTION: put_char_between_every_char_in_string()
// Puts a given character in every even index in a string.
// Essentially splitting every character in the string
//
// PARAMETERS:
// str (string&) -> the string which will be split
// c (char) -> the character which will be added
//
// RETURNS:
// none
//-------------------------------------------------------------------
void put_char_between_every_char_in_string(string &str, char c);

#endif //LOGICAL_EXPRESSION_INTERPRETER_STRING_UTILS_HH
