#ifndef LOGICAL_COMMAND_INTERPRETER_COMMAND_HH
#define LOGICAL_COMMAND_INTERPRETER_COMMAND_HH

#include <string>
#include <stdexcept>
#include "../utils/string_utils.hh"
using namespace std;

enum Command {
    DEFINE,
    SOLVE,
    FIND,
    ALL,
    QUIT
};

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
// std::invalid_argument -> when the string command doesn't exist in the enum
//-------------------------------------------------------------------
Command get_command_from_string(string &command);

//-------------------------------------------------------------------
// FUNCTION: get_command()
// Splits the command from the line
//
// PARAMETERS:
// line (string&) -> the line
//
// RETURNS:
// (Command) -> the command as enum type
//
// THROWS:
// std::runtime_error -> when the command cannot be extracted
//-------------------------------------------------------------------
Command get_command(string &line);

#endif //LOGICAL_COMMAND_INTERPRETER_COMMAND_HH
