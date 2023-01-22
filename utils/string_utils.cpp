#include "string_utils.hh"

bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_letter_or_digit(char c) {
    return is_letter(c) || is_digit(c);
}

int get_length(string &str) {
    int len = 0;
    for (; str[len] != '\0'; len++);
    return len;
}

int count_chars(char c, string &str) {
    int count = 0;
    for (int i = 0; i < get_length(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }

    return count;
}

int find_first(char c, string &str) {
    // return index of first occurrence of the character
    // if character is not found return -1
    for (int i = 0; i < get_length(str); i++) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

int remove_char_at_index(int index, string &str) {
    // get string length
    int len = get_length(str);
    // check if index is in bounds of the string
    if (index < 0 || index >= len) {
        return -1;
    }
    string new_str((len - 1), ' ');
    // put chars until index in new string
    for (int i = 0; i < index; i++) {
        new_str[i] = str[i];
    }
    // move chars in string one position backwards from index to the end
    for (int i = index; i < len - 1; i++) {
        new_str[i] = str[i + 1];
    }
    // set new string
    str = new_str;
    return 0;
}

void remove_all_chars(char c, string &str) {
    int len = get_length(str);
    for (int i = 0; i < len; i++) {
        // remove character
        if (str[i] == c) {
            // i--, because the character at the current index is being
            // deleted and otherwise the next character will be skipped
            remove_char_at_index(i--, str);
            len--;
        }
    }
}

int replace_char_at_index(int index, char c, string &str) {
    // check if index is in bounds of the string
    if (index < 0 || index >= get_length(str)) {
        throw runtime_error("Index out of bounds!");
    }
    // replace character
    str[index] = c;
    return 0;
}

void trim_spaces(string &str) {
    // trim redundant spaces
    trim_leading_spaces(str);
    trim_trailing_spaces(str);
    trim_duplicate_spaces(str);
}

void trim_leading_spaces(string &str) {
    int i = 0;
    // remove first character of string while it is a space
    while (str[i] == ' ') {
        remove_char_at_index(0, str);
    }
}

void trim_trailing_spaces(string &str) {
    int i = get_length(str) - 1;
    // remove last character of string while it is a space
    while (str[i] == ' ') {
        remove_char_at_index(i--, str);
    }
}

void trim_duplicate_spaces(string &str) {
    int len = get_length(str);
    for (int i = 0; i < len - 1; i++) {
        // remove second space if two characters in a row are spaces
        while (str[i] == str[i + 1] && str[i] == ' ') {
            remove_char_at_index(i + 1, str);
            len--;
        }
    }
}

Vector<char> split_string_to_chars(char separator, string &str) {
    // result vector
    Vector<char> arr;
    // get length of string
    int len = get_length(str);

    // if only one element then return it
    if (len == 1) {
        arr.push_back(str[0]);
        return arr;
    }

    // size of the array that will be returned
    int size = count_chars(separator, str) + 1;
    if (size == 1) {
        // cast to string so that in can be appended to error message
        string sep(1, separator);
        string error = "Character not found: \"" + sep + "\"! Cannot be used as a separator";
        throw invalid_argument(error);
    }

    // populate arr
    // - 1, cause last element has no separator at the end
    int index_of_c;
    string element;
    for (int i = 0; i < size - 1; i++) {
        // get next element
        index_of_c = find_first(separator, str);
        // split str at the index of the separator
        element = split_string_at_index_return_first(index_of_c, str);
        // ensure operand is a character
        if (get_length(element) != 1) {
            string error = "Invalid argument for expression: Expected chars, found string: " + element;
            throw invalid_argument(error);
        }
        arr.push_back(element[0]);
        // subtract length of element from length of string
        // + 1 because of the separator
        len -= index_of_c + 1;
    }
    // ensure last operand is a character and add it
    if (get_length(str) != 1) {
        string error = "Invalid argument for expression: Expected chars, found string: " + str;
        throw invalid_argument(error);
    }
    arr.push_back(str[0]);

    return arr;
}

Vector<string> split_string_to_strings(char separator, string &str) {
    // result vector
    Vector<string> arr;
    // get length of string
    int len = get_length(str);

    // size of the array that will be returned
    int size = count_chars(separator, str) + 1;
    if (size == 1) {
        // cast to string so that in can be appended to error message
        string sep(1, separator);
        string error = "Character not found: \"" + sep + "\"! Cannot be used as a separator";
        throw invalid_argument(error);
    }

    // populate arr
    // - 1, cause last element has no separator at the end
    int index_of_c;
    string element;
    for (int i = 0; i < size - 1; i++) {
        // get next element
        index_of_c = find_first(separator, str);
        // split str at the index of the separator
        element = split_string_at_index_return_first(index_of_c, str);
        arr.push_back(element);
        // subtract length of element from length of string
        // + 1 because of the separator
        len -= index_of_c + 1;
    }
    arr.push_back(str);

    return arr;
}

string split_string_at_index_return_first(int index, string &str) {
    // check if index is in bounds
    if (index < 0 || index >= get_length(str)) {
        throw invalid_argument("Index out of bounds");
    }

    string first_part(index, ' ');

    for (int i = 0; i < index; i++) {
        // put every character up to index in new string
        first_part[i] = str[0];
        // remove the character from the original string
        remove_char_at_index(0, str);
    }
    // remove space
    remove_char_at_index(0, str);

    return first_part;
}

void add_substring_to_string(int index, string &str, string substr) {
    // get length of both string
    int str_length = get_length(str);
    int substr_length = get_length(substr);
    // create result string
    string result(str_length + substr_length, ' ');

    // put characters before index in result
    for (int i = 0; i < index; i++) {
        result[i] = str[i];
    }

    // put substr in result
    for (int i = 0; i < substr_length; i++) {
        result[index + i] = substr[i];
    }

    // put characters after index in result
    for (int i = index; i < str_length; i++) {
        result[i + substr_length] = str[i];
    }

    // set result
    str = result;
}

void remove_substring_from_string(int begin, int end, string &str) {
    // get length of string
    int length = get_length(str);
    // check if begin is out of bounds
    if (begin <= 0 || begin >= length) {
        throw invalid_argument("Begin index is out of bounds!");
    }
    // check if end is out of bounds
    if (end <= 0 || end >= length) {
        throw invalid_argument("End index is out of bounds!");
    }
    // check if begin is bigger than end
    if (begin >= end) {
        throw invalid_argument("Begin index is bigger than end index!");
    }
    for (int i = begin; i <= end; i++) {
        if (remove_char_at_index(begin, str) == -1) {
            throw runtime_error("Error removing character from string!");
        }
    }
}

void put_char_between_every_char_in_string(string &str, char c) {
    // get length of str
    int len = get_length(str);
    // declare new string
    string new_str = string(2 * len - 1, ' ');

    // put first character into the new string
    new_str[0] = str[0];
    // put rest of them with separators
    for (int i = 1, j = 1; i < len; i++, j+=2) {
        new_str[j] = c;
        new_str[j+1] = str[i];
    }
    // set new string
    str = new_str;
}