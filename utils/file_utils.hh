#ifndef LOGICAL_EXPRESSION_INTERPRETER_FILE_UTILS_HH
#define LOGICAL_EXPRESSION_INTERPRETER_FILE_UTILS_HH

#include <string>
#include <fstream>
#include <stdexcept>
#include "../data_types/vector.hh"

using namespace std;

//-------------------------------------------------------------------
// FUNCTION: read_lines_from_file()
// Reads all lines from a file
//
// PARAMETERS:
// filename (string) -> the name of the file
//
// RETURNS:
// (Vector<string>) -> a vector with the lines
//-------------------------------------------------------------------
Vector<string> read_lines_from_file(string filename);

//-------------------------------------------------------------------
// FUNCTION: insert_line_in_file()
// Appends a line to a file
//
// PARAMETERS:
// filename (string) -> the name of the file
// line (string) -> the new line for the file
//
// RETURNS:
// none
//-------------------------------------------------------------------
void insert_line_in_file(string filename, string line);

#endif //LOGICAL_EXPRESSION_INTERPRETER_FILE_UTILS_HH
