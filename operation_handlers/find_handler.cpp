#include "find_handler.hh"

void validate_entries(Vector<string> entries) {
    // validate that all values have the same length
    for (int i = 0; i < entries.size() - 1; i++) {
        // check every two consecutive values
        if (entries[i].size() != entries[i + 1].size()) {
            throw invalid_argument("Arguments of find command must have the same length");
        }
    }
}

string get_arguments_from_entry(string entry) {
    // get length of value
    int len = get_length(entry);
    // define string for arguments
    string args(len - 1, ' ');
    // add args to new string
    for (int i = 0; i < len - 1; i++) {
        args[i] = entry[i];
    }
    return args;
}

char get_result_from_entry(string entry) {
    return entry[get_length(entry) - 1];
}

void populate_truth_table(TruthTable &tb, int argument_count, Vector<string> entries, char params[], int curr_argument) {
    if (curr_argument == argument_count) {
        // transform to char array to string
        Vector<char> p;
        for (int i = 0; i < argument_count; i++) {
            p.push_back(params[i]);
        }
        // get vector of params to string
        string args = p.to_string();
        // check if current combination exists in entries
        for (int i = 0; i < entries.size(); i++) {
            string key = get_arguments_from_entry(entries[i]);
            char result = get_result_from_entry(entries[i]);
            if (key == args) {
                // check if result is 0, then return, as 0 are not used
                if (result == '0') {
                    return;
                }
                // check if result is 1, then insert in truth table
                if (result == '1') {
                    tb.update(key, 1);
                    return;
                }
                // check if result is "x", then insert in truth table, "don't care" values are also used
                if (result == 'x') {
                    tb.update(key, 2);
                    return;
                }
            }
        }
        // current combination doesn't exist so add to truth table as "don't care"
        tb.update(args, 2);
    } else {
        for (int i = 0; i <= 1; i++) {
            // convert to ASCII code 48 for 0 and 49 for 1
            params[curr_argument] = (i + 48);
            // continue with recursion
            populate_truth_table(tb, argument_count, entries, params, curr_argument + 1);
        }
    }
}

bool can_be_combined(string s1, string s2) {
    if (get_length(s1) != get_length(s2)) {
        throw invalid_argument("Different length of arguments of find command");
    }
    // if 1 different - ok
    // if more - return
    bool have_one_different = false;
    for (int i = 0; i < get_length(s1); i++) {
        if (s1[i] != s2[i]) {
            // have more than one different
            if (have_one_different) {
                return false;
            }
            // now they have exactly one different
            have_one_different = true;
        }
    }
    return true;
}

string combine(string s1, string s2) {
    // get length of strings
    int len = get_length(s1);
    string combined(len, ' ');

    for (int i = 0; i < len; i++) {
        if (s1[i] == s2[i]) {
            // if same - add to combined
            combined[i] = s1[i];
        } else {
            // if different - add "-" as this argument is not needed
            combined[i] = '-';
        }
    }
    return combined;
}

bool is_minterm_included(string minterm, Queue<Implicant> implicants) {
    // iterate implicants of this level
    for (int i = 0; i < implicants.size(); i++) {
        // iterate every minterm
        for (int j = 0; j < implicants[i].minterms().size(); j++) {
            if (implicants[i].minterms()[j] == minterm) {
                return true;
            }
        }
    }
    return false;
}

Queue<Implicant> get_possible_combinations(Queue<Implicant> original, int level) {
    // create queue for implicants for this level
    Queue<Implicant> my_implicants;

    // iterate every variation to check for possible combinations
    for (int i = 0; i < original.size() - 1; i++) {
        for (int j = i + 1; j < original.size(); j++) {
            if (can_be_combined(original[i].combined(), original[j].combined())) {
                // generate combined string
                string combined = combine(original[i].combined(), original[j].combined());

                // check if this implicant exists with different order of the minterms
                bool exists = false;
                for (int k = 0; k < my_implicants.size(); k++) {
                    if (my_implicants[k].combined() == combined) {
                        exists = true;
                    }
                }
                if (exists) {
                    continue;
                }

                // create vector with combination
                Vector<string> minterms;
                // add minterms
                for (int k = 0; k < level / 2; k++) {
                    // add every minterm of the implicant
                    // at level x, there are x / 2 implicants to be added
                    // and the total will become x
                    minterms.push_back(original[i].minterms()[k]);
                }
                for (int k = 0; k < level / 2; k++) {
                    minterms.push_back(original[j].minterms()[k]);
                }
                // create implicant and add to queue
                my_implicants.enqueue(Implicant(minterms.size(), minterms, combined));
            }
        }
    }

    return my_implicants;
}

Queue<Implicant> combine_entries(Queue<Implicant> original, int level) {
    // get possible combinations of implicants for this level
    Queue<Implicant> my_implicants = get_possible_combinations(original, level);

    if (my_implicants.is_empty()) {
        // this level is one above the max
        // nothing more can be added
        return my_implicants;
    }

    // combine implicants on the next level
    Queue<Implicant> incoming = combine_entries(my_implicants, level * 2);

    if (incoming.size() == 0) {
        // this level is the max
        // nothing more can be added
        return my_implicants;
    }

    // check if every minterm of this level is included in a combination of a higher level
    // if not, add the implicant
    // iterate implicants of this level
    for (int i = 0; i < my_implicants.size(); i++) {
        // iterate every minterm
        for (int j = 0; j < my_implicants.first().size(); j++) {
            if (!is_minterm_included(my_implicants[i].minterms()[j], incoming)) {
                incoming.enqueue(my_implicants[i]);
            }
        }
    }

    return incoming;
}

Queue<Implicant> remove_dont_care_minterms_from_implicants(Queue<Implicant> implicants, TruthTable tb) {
    Queue<Implicant> only_ones;
    // iterate through implicants
    for (int i = 0; i < implicants.size(); i++) {
        // create minterm vector that will contain only 1s
        Vector<string> minterms_only_ones;
        // iterate through every minterm
        for (int j = 0; j < implicants[i].minterms().size(); j++) {
            // get minterm value from truth table
            // if the minterm value is 1, add to only 1s
            if (tb.get(implicants[i].minterms()[j]) == 1) {
                minterms_only_ones.push_back(implicants[i].minterms()[j]);
            }
        }
        // create new implicant if there are minterms
        if (!minterms_only_ones.is_empty()) {
            // size - size of only ones minterms
            // combined - same combined as the implicant
            only_ones.enqueue(Implicant(minterms_only_ones.size(), minterms_only_ones, implicants[i].combined()));
        }
    }

    return only_ones;
}

Queue<Implicant> try_to_remove_unnecessary_implicants(Queue<Implicant> implicants) {
    // remove each implicant one by one and see if each of its minterms
    // are present in the rest of the implicants
    for (int i = 0; i < implicants.size(); i++) {
        // remove implicant from queue
        Implicant implicant = implicants.dequeue();
        // iterate through every minterm of the removed implicant
        for (int j = 0; j < implicant.minterms().size(); j++) {
            if (!is_minterm_included(implicant.minterms()[j], implicants)) {
                // if a given minterm is not included in the rest of the implicants
                // return implicant to the rest of the implicants
                implicants.enqueue(implicant);
                break;
            }
        }
    }

    return implicants;
}

string convert_implicants_to_expression(Queue<Implicant> implicants) {
    Vector<char> expression;
    // iterate through every implicant
    for (int i = 0; i < implicants.size(); i++) {
        // get combined of implicant
        string combined = implicants[i].combined();

        // iterate through every character of combined
        for (int j = 0; j < get_length(combined); j++) {
            // if character is 1 -> normal
            // if character is 0 -> inverted
            // if character is - -> skip
            char c = combined[j];
            if (c == '-') {
                // skip as it is not critical
                continue;
            }
            // add 65 to get to ascii code for every iterator
            // i.e. - j = 0, so variable is 65
            char variable = j + 65;
            // if character is 0 -> add !
            if (c == '0') {
                expression.push_back('!');
            }
            // add variable to expression
            expression.push_back(variable);
            // add and
            // add spaces for better formatting
            expression.push_back(' ');
            expression.push_back('&');
            expression.push_back(' ');
        }
        // pop last or and last two spaces
        for (int j = 0; j < 3; j++) {
            expression.pop();
        }

        // add or
        // add spaces for better formatting
        expression.push_back(' ');
        expression.push_back('|');
        expression.push_back(' ');
    }
    // pop last or and last two spaces
    for (int i = 0; i < 3; i++) {
        expression.pop();
    }


    return expression.to_string();
}

void process_find(string &line) {
    // remove all spaces from the find command for easier processing
    remove_all_chars(' ', line);

    // split the command into separate arguments-result strings
    Vector<string> entries = split_string_to_strings(',', line);

    // validate that all entries have the same length
    validate_entries(entries);

    // get count of character in each entry
    int entry_size = entries[0].size();

    // populate truth table only with entries that have result 1 or "don't care"
    TruthTable tb;
    // -1 because value is not counted
    char params[entry_size - 1];
    populate_truth_table(tb, entry_size - 1, entries, params, 0);

    // ensure there is at least one 1 in the truth table
    bool valid = false;
    for (int i = 0; i < tb.size(); i++) {
        if (tb.values()[i] == 1) {
            valid = true;
        }
    }
    if (!valid) {
        throw invalid_argument("Truth table has no 1 and thus an expression cannot be extracted");
    }

    // create queue of implicants for first level based on the truth table
    Queue<Implicant> original_implicants;
    for (int i = 0; i < tb.size(); i++) {
        // create minterms (only 1)
        Vector<string> minterms;
        minterms.push_back(tb.keys()[i]);
        // combined is the same as the minterm as it is only 1
        original_implicants.enqueue(Implicant(1, minterms, tb.keys()[i]));
    }

    // get combined implicants recursively to the highest possible level
    Queue<Implicant> combined_implicants = combine_entries(original_implicants, 2);

    // remove "don't care"s minterms, as they are not needed for the result
    Queue<Implicant> only_ones_implicants = remove_dont_care_minterms_from_implicants(combined_implicants, tb);

    // remove implicants whose minterms are included in the rest of the implicants
    Queue<Implicant> final_implicants = try_to_remove_unnecessary_implicants(only_ones_implicants);

    // convert implicants to expression
    string expression = convert_implicants_to_expression(final_implicants);

    cout << "Expression for this truth table: \"" << expression << "\""<< endl;
}