#include <string>
#include <iostream>

#include "operation_handlers/define_handler.hh"
#include "operation_handlers/solve_handler.hh"
#include "operation_handlers/truth_table_handler.hh"
#include "operation_handlers/find_handler.hh"
#include "data_types/queue.hh"
#include "data_types/function.hh"
#include "utils/file_utils.hh"
#include "utils/string_utils.hh"
#include "enumerations/command.hh"

using namespace std;

//     DEFINE   func1(a,  b): "a & b "
// DEFINE func1(): "a & b"
// DEFINE func1(a): "a & c"
// DEFINE func1() "a & b"
// DEFINE func1): "a & b"
// DEFINE func1(a, b: "a & b"
// DEFINE func1(a, b): a & b"
// DEFINE func1(a, b): "a & b

//     DEFINE   func(a,  b): "a & b "
// DEFINE func1(a, b): "a & b"
// DEFINE func2(a, b, c): "func1(a, b) | c"
// DEFINE func3(a, b, c): "func1(a, b, c) | c"
// DEFINE func4(a, b, c): "a | b & !c"

// DEFINE func5(a,b): "(a|!b)|(!a&!b)&(a&b)"
// DEFINE func6(a,b): "(a|b)|(a&b)&(a&b)"
// DEFINE func7(a,b): "(a|b)&(!a&b)|(!a&b)|(a|!b)"

// SOLVE func1(1, 0)
// Result: 0
// SOLVE func2(1, 0, 1)
// Result: 1
// SOLVE func5(0, 0)
// SOLVE func5(0, 1)
// SOLVE func5(1, 0)
// SOLVE func5(1, 1)
// Result:

// ALL func4

// FIND 0001,0010,0101,0110,1000,1010,1101,1111
// FIND 00000,00010,00100,00110,01001,01010,01100,01110,10001,1001x,10101,10111,11001,11010,1110x,11111

Queue<Function> get_functions_from_file(string filename) {
    Queue<Function> functions;
    // get commands from file
    Vector<string> lines = read_lines_from_file(filename);
    // generate functions from lines
    string line;
    for (int i = 0; i < lines.size(); i++) {
        // get line
        line = lines[i];

        // check for commas count in line
        if (count_chars(',', line) != 2) {
            cerr << "Invalid entry in \"" << filename << "\": \"" << line << "\"" << endl;
            continue;
        }

        // split line at commas
        Vector<string> function_definition = split_string_to_strings(',', line);

        // extract function data
        string function_name = function_definition[0];
        Vector<char> function_args;
        for (int j = 0; j < get_length(function_definition[1]); j++) {
            function_args.push_back(function_definition[1][j]);
        }
        string function_expression = function_definition[2];

        // add function to queue of functions
        functions.enqueue(Function(function_name, function_expression, function_args));
        cout << "Added function: name - " << function_name << ", args - "
            << function_args.to_string() << ", expression - " << function_expression << endl;
    }

    return functions;
}

int main(int argc, char *argv[]) {
    Queue<Function> functions;

    // check for file name in arguments
    if (argc > 1) {
        try {
            functions = get_functions_from_file(argv[1]);
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }
    }

    string line;
    while (true) {
        // get line from console
        getline(cin, line);

        // trim spaces from line
        trim_spaces(line);

        // get command
        Command command;
        try {
            command = get_command(line);
        } catch (const exception &e) {
            cerr << e.what() << endl;
            continue;
        }

        try {
            switch (command) {
                // DEFINE
                case DEFINE: {
                    Function function = process_define(line, functions);
                    functions.enqueue(function);
                    break;
                }
                // SOLVE
                case SOLVE: {
                    process_solve(line, functions);
                    break;
                }
                // FIND
                case FIND: {
                    process_find(line);
                    break;
                }
                // ALL
                case ALL: {
                    process_all(line, functions);
                    break;
                }
                // QUIT
                case QUIT:
                    return 0;
            }
        } catch (const exception &e) {
            cerr << "Exception caught: " << e.what() << endl;
        }
    }
}
