#include "string_utils.hh"

int get_length(string &str) {
    int len = 0;
    for (; str[len] != '\0'; len++);
    return len;
}

int count_chars(char c, string &str, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            count++;
        }
    }

    return count;
}

int find_first(char c, string &str, int len) {
    // return index of first occurrence of the character
    // if character is not found return -1
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

int remove_char_at_index(int index, string &str, int len) {
    // check if index is in bounds of the string
    if (index < 0 || index >= len) {
        return -1;
    }
    // move chars in string one position backwards from index to the end
    for (int i = index; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    // set last character to terminal 0
    str[len - 1] = '\0';
    return 0;
}

void remove_all_chars(char c, string &str, int &len) {
    for (int i = 0; i < len; i++) {
        // remove character
        if (str[i] == c) {
            // i--, because the character at the current index is being
            // deleted and otherwise the next character will be skipped
            remove_char_at_index(i--, str, len--);
        }
    }
}

int replace_char_at_index(int index, char c, string &str, int len) {
    // check if index is in bounds of the string
    if (index < 0 || index >= len) {
        return -1;
    }
    // replace character
    str[index] = c;
    return 0;
}

void trim_spaces(string &str, int &len) {
    // trim redundant spaces
    trim_leading_spaces(str, len);
    trim_trailing_spaces(str, len);
    trim_duplicate_spaces(str, len);
}

void trim_leading_spaces(string &str, int &len) {
    int i = 0;
    // remove first character of string while it is a space
    while (str[i] == ' ') {
        remove_char_at_index(0, str, len--);
    }
}

void trim_trailing_spaces(string &str, int &len) {
    int i = len - 1;
    // remove last character of string while it is a space
    while (str[i] == ' ') {
        remove_char_at_index(i--, str, len--);
    }
}

void trim_duplicate_spaces(string &str, int &len) {
    for (int i = 0; i < len - 1; i++) {
        // remove second space if two characters in a row are spaces
        while (str[i] == str[i + 1] && str[i] == ' ') {
            remove_char_at_index(i + 1, str, len--);
        }
    }
}

Vector<string> split_string(char separator, string &str, int len) {
    // size of the array that will be returned
    int size = count_chars(separator, str, len) + 1;
    if (size == 1) {
        throw runtime_error("Character not found!");
    }

    Vector<string> arr;

    // populate arr
    // - 1, cause last element has no separator at the end
    int index_of_c;
    string element;
    for (int i = 0; i < size - 1; i++) {
        // get next element
        index_of_c = find_first(separator, str, len);
        // split str at the index of the separator
        element = split_string_at_index_return_first(index_of_c, str, len);
        arr.push_back(element);
        // subtract length of element from length of string
        // + 1 because of the separator
        len -= index_of_c + 1;
    }
    // add last element
    arr.push_back(str);

    return arr;
}

string split_string_at_index_return_first(int index, string &str, int len) {
    string first_part(index, ' ');

    for (int i = 0; i < index; i++) {
        // put every character up to index in new string
        first_part[i] = str[0];
        // remove the character from the original string
        remove_char_at_index(0, str, len--);
    }
    // remove space
    remove_char_at_index(0, str, len--);

    return first_part;
}

Command get_command_from_string(string &command) {
    if (command == "DEFINE") {
        return DEFINE;
    } else if (command == "SOLVE") {
        return SOLVE;
    } else if (command == "FIND") {
        return FIND;
    } else if (command == "ALL") {
        return ALL;
    } else if (command == "QUIT") {
        return QUIT;
    } else {
        throw invalid_argument("Unsupported command");
    }
}