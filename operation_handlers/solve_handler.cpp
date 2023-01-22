#include "solve_handler.hh"

string get_function_name_for_solve(string &command) {
    // get function name
    int index_of_left_bracket = find_first('(', command);
    if (index_of_left_bracket == -1) {
        throw runtime_error("Couldn't extract function name from the solve command! Reason: Missing \"(\"!");
    }
    // split function name from the solve command
    string func_name = split_string_at_index_return_first(index_of_left_bracket, command);

    return func_name;
}

string get_function_arguments_for_solve(string &command) {
    // get length of solve command arguments
    int len = get_length(command);

    // assert that last character is closing bracket
    if (command[len - 1] != ')') {
        throw runtime_error("Wrong formatting of solve command arguments! Reason: Missing \")\"!");
    }
    // remove last character
    remove_char_at_index(len - 1, command);

    return command;
}

void process_solve(string &line, Queue<Function> &functions) {
    // remove all spaces from the solve command for easier processing
    remove_all_chars(' ', line);

    // get function name from solve command
    string func_name = get_function_name_for_solve(line);

    // get function arguments from solve command as string
    string func_args = get_function_arguments_for_solve(line);

    // split arguments
    Vector<char> func_arguments = split_string_to_chars(',', func_args);

    // try getting the function if it exists
    Function &function = functions.get(func_name, func_arguments.size());

    // solve function
    int result = function.solve(func_arguments);

    cout << "Result: " << result << endl;
}

