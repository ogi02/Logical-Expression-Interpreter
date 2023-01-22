#include "truth_table_handler.hh"

void generate_truth_table(Function function, int argument_count, char params[], int curr_argument) {
    if (curr_argument == argument_count) {
        // solve for the current combination of arguments
        Vector<char> p;
        for (int i = 0; i < argument_count; i++) {
            p.push_back(params[i]);
        }
        int result = function.solve(p);
        // get vector of params to string
        string formatted_arguments = p.to_string();
        // put | between each argument for formatting
        put_char_between_every_char_in_string(formatted_arguments, '|');
        // print out the current combination of arguments with the solution
        cout << formatted_arguments << "|" << result << endl;
    } else {
        for (int i = 0; i <= 1; i++) {
            // convert to ASCII code 48 for 0 and 49 for 1
            params[curr_argument] = (i + 48);
            // continue with recursion
            generate_truth_table(function, argument_count, params, curr_argument + 1);
        }
    }
}

void process_all(string &line, Queue<Function> functions) {
    // remove all spaces from the all command for easier processing
    remove_all_chars(' ', line);

    // get function by name
    Function function = functions.get_by_function_name(line);

    // print first line with arguments and result columns
    for (int i = 0; i < function.arguments().size(); i++) {
        cout << function.arguments()[i] << "|";
    }
    cout << "res" << endl;

    // generate and print truth table
    int arg_count = function.arguments().size();
    char params[arg_count];
    generate_truth_table(function, arg_count, params, 0);
}
