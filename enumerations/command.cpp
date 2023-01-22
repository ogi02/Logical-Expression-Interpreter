#include "command.hh"

Command get_command_from_string(string &command) {
    if (command == "DEFINE") {
        return Command::DEFINE;
    } else if (command == "SOLVE") {
        return Command::SOLVE;
    } else if (command == "FIND") {
        return Command::FIND;
    } else if (command == "ALL") {
        return Command::ALL;
    } else if (command == "QUIT") {
        return Command::QUIT;
    } else {
        throw invalid_argument("Unsupported command");
    }
}

Command get_command(string &line) {
    // check if command is QUIT
    if (line == "QUIT") {
        return Command::QUIT;
    }

    // get command
    int index_of_first_space = find_first(' ', line);
    if (index_of_first_space == -1) {
        throw runtime_error("Couldn't extract operation from command!");
    }
    // split command from the rest of the command
    string cmd = split_string_at_index_return_first(index_of_first_space, line);

    // convert to enumeration type
    Command command = get_command_from_string(cmd);

    return command;
}
