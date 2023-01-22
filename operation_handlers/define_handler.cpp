#include "define_handler.hh"

string get_function_declaration(string &definition) {
    int index_of_colon = find_first(':', definition);
    if (index_of_colon == -1) {
        throw runtime_error("Couldn't extract function name and arguments from definition! Reason: Missing \":\"!");
    }
    // split function declaration from the function body
    string func_decl = split_string_at_index_return_first(index_of_colon, definition);
    return func_decl;
}

string get_function_name_for_define(string &func_decl, Queue<Function> existing_functions) {
    // get function name
    int index_of_left_bracket = find_first('(', func_decl);
    if (index_of_left_bracket == -1) {
        throw runtime_error("Couldn't extract function name from definition! Reason: Missing \"(\"!");
    }
    // split function name from the function declaration
    string func_name = split_string_at_index_return_first(index_of_left_bracket, func_decl);

    // check for duplicate function name
    for (int i = 0; i < existing_functions.size(); i++) {
        if (func_name == existing_functions[i].name()) {
            string error = "Function with name \"" + func_name + "\" already exists!";
            throw invalid_argument(error);
        }
    }

    return func_name;
}

string get_function_arguments_for_define(string &func_decl) {
    // get length of function arguments
    int func_decl_length = get_length(func_decl);

    // assert that last character is closing bracket
    if (func_decl[func_decl_length - 1] != ')') {
        throw runtime_error("Wrong formatting of function arguments! Reason: Missing \")\"!");
    }
    // remove last character
    remove_char_at_index(func_decl_length - 1, func_decl);

    return func_decl;
}

Vector<char> get_function_expression(string &expression, Vector<char> arguments, Queue<Function> existing_functions) {
    // get length of expression
    int len = get_length(expression);

    // check for functions in expression
    for (int i = 0; i < get_length(expression) - 1; i++) {
        if (is_letter(expression[i]) && is_letter_or_digit(expression[i + 1])) {
            // validate function used in expression
            validate_function_in_expression(expression, i, existing_functions);
        }
    }

    // if last character is operator -> already in rpn
    if (is_operator(expression[len - 1])) {
        // vector from string
        return Vector<char>(expression, len);
    }

    // convert to rpn
    return convert_to_rpn(expression, arguments);
}

Function validate_function_in_expression(string &expression, int begin, Queue<Function> existing_functions) {
    int start_of_arguments;
    // extract function name of the function used in the expression
    string possible_function_name;
    for (start_of_arguments = begin; expression[start_of_arguments] != '('; start_of_arguments++) {
        possible_function_name.push_back(expression[start_of_arguments]);
    }

    // end of function usage in expression
    int end;
    // extract function arguments of the function used in the expression
    string arguments;
    // + 1 to skip '('
    for (end = start_of_arguments + 1; expression[end] != ')'; end++) {
        arguments.push_back(expression[end]);
    }

    // split arguments of the function used in the expression
    Vector<char> function_arguments = split_string_to_chars(',', arguments);

    // try getting the function if it exists
    Function function = existing_functions.get(possible_function_name, function_arguments.size());

    // replace function in expression with its expression
    remove_substring_from_string(begin, end, expression);
    add_substring_to_string(begin, expression, function.rpn_expression());

    return function;
}

Function process_define(string &definition, Queue<Function> existing_functions) {
    // remove all spaces from the definition for easier processing
    remove_all_chars(' ', definition);

    // get function declaration (name + arguments)
    string func_decl = get_function_declaration(definition);

    // get function name
    string func_name = get_function_name_for_define(func_decl, existing_functions);

    // get function arguments
    string func_args = get_function_arguments_for_define(func_decl);

    // split arguments
    Vector<char> func_arguments = split_string_to_chars(',', func_args);

    // get rpn expression from definition
    Vector<char> rpn_expression = get_function_expression(definition, func_arguments, existing_functions);

    // create function
    Function function(func_name, rpn_expression.to_string(), func_arguments);

    cout << "Created function \"" << function.name() << "\" that takes " << function.arguments().size()
        << " arguments and has the following expression: " << function.rpn_expression() << endl;

    return function;
}
