#include "define_handler.hh"

string get_function_declaration(string &definition) {
    // get length of definition
    int len = get_length(definition);

    int index_of_colon = find_first(':', definition, len);
    if (index_of_colon == -1) {
        throw runtime_error("Couldn't extract function name and arguments from definition! Reason: Missing \":\"!");
    }
    // split function declaration from the function body
    string func_decl = split_string_at_index_return_first(index_of_colon, definition, len);
    return func_decl;
}

string get_function_name(string &func_decl) {
    // get length of function declaration
    int func_decl_length = get_length(func_decl);

    // get function name
    int index_of_left_bracket = find_first('(', func_decl, func_decl_length);
    if (index_of_left_bracket == -1) {
        throw runtime_error("Couldn't extract function name from definition! Reason: Missing \"(\"!");
    }
    // split function name from the function declaration
    string func_name = split_string_at_index_return_first(index_of_left_bracket, func_decl,
                                                          func_decl_length);
    return func_name;
}

string get_function_arguments(string &func_decl) {
    // get length of function arguments
    int func_decl_length = get_length(func_decl);

    // assert that last character is closing bracket
    if (func_decl[func_decl_length - 1] != ')') {
        throw runtime_error("Wrong formatting of function arguments! Reason: Missing \")\"!");
    }
    // remove last character
    remove_char_at_index(func_decl_length - 1, func_decl, func_decl_length);

    return func_decl;
}

Vector<char> get_function_expression(string &expression) {
    // get length of expression
    int len = get_length(expression);

    // if last character is operator -> already in rpn
    if (is_operator(expression[len - 1])) {
        // vector from string
        return Vector<char>(expression, len);
    }

    // convert to rpn
    return convert_to_rpn(expression);
}

Function process_define(string &definition, int len) {
    // remove all spaces from the definition for easier processing
    remove_all_chars(' ', definition, len);

    string func_decl, func_name, func_args;
    Vector<string> func_arguments;
    try {
        // get function declaration (name + arguments)
        func_decl = get_function_declaration(definition);

        // get function name
        func_name = get_function_name(func_decl);

        // get function arguments
        func_args = get_function_arguments(func_decl);

        // split arguments
        func_arguments = split_string(',', func_args, get_length(func_args));
    } catch (const exception &e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    // get rpn expression from definition
    Vector<char> rpn_expression = get_function_expression(definition);

    // create function
    Function function(func_name, rpn_expression.to_string(), func_arguments);

    cout << function.name() << "\n" << function.rpn_expression() << "\n" << function.arguments().size() << endl;

    return function;
}
