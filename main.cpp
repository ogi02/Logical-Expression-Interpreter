#include <string>
#include <iostream>

#include "function.hh"
#include "string_utils.hh"
#include "define_handler.hh"

using namespace std;

//     DEFINE   func1(a,  b): "a & b "
// DEFINE func1(a,b): "(a|!b)|(!a&!b)&(a&b)"
// DEFINE func1(): "a & b"
// DEFINE func1() "a & b"
// DEFINE func1): "a & b"
// DEFINE func1(a, b "a & b"
// DEFINE func1(a,b,c,  de): ""

void process_solve() {

}

void process_find() {

}

void process_all() {
    
}

Command get_command(string &line, int len) {
    // get command
    int index_of_first_space = find_first(' ', line, len);
    if (index_of_first_space == -1) {
        throw runtime_error("Couldn't extract operation from command!");
    }
    // split command from the rest of the command
    string cmd = split_string_at_index_return_first(index_of_first_space, line, len);

    Command command = get_command_from_string(cmd);

    return command;
}

int main() {

//    string infix = "(a|!b)|(!a&!b)&(a&b)";
//    string expected = "ab!|a!b!&ab&&|";
//    string postfix = convert_to_rpn(infix).to_string();
//    cout << postfix << endl;
//
//    return 0;

    string line;
    while (true) {
        // get line from console
        getline(cin, line);

        // get line length
        int len = get_length(line);

        // trim spaces from line
        trim_spaces(line, len);

        // get command
        Command command;
        try {
            command = get_command(line, len);
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }

        switch (command) {
            case DEFINE: {
                Function function = process_define(line, get_length(line));
                break;
            }
            case SOLVE:
                process_solve();
                break;
            case FIND:
                process_find();
                break;
            case ALL:
                process_all();
                break;
            case QUIT:
                break;
            default:
                break;
        }
    }

    return 0;
}
