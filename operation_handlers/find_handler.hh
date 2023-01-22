#ifndef LOGICAL_EXPRESSION_INTERPRETER_FIND_HANDLER_HH
#define LOGICAL_EXPRESSION_INTERPRETER_FIND_HANDLER_HH

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

#include "../utils/string_utils.hh"
#include "../data_types/queue.hh"
#include "../data_types/implicant.hh"
#include "../data_types/truth_table.hh"

//-------------------------------------------------------------------
// FUNCTION: validate_entries()
// Validate that all entries, i.e. - all truth table values have the same length
//
// PARAMETERS:
// entries (Vector<string>) -> the entries that will be checked
//
// RETURNS:
// none
//
// THROWS:
// std::invalid_argument -> if an entry has different length than the others
//-------------------------------------------------------------------
void validate_entries(Vector<string> entries);

//-------------------------------------------------------------------
// FUNCTION: get_arguments_from_entry()
// Gets the truth table arguments from an entry
// Gets all characters but the last one from an entry
// as the last character is for the value
//
// PARAMETERS:
// entry (string) -> the given entry
//
// RETURNS:
// (string) -> the arguments of the entry
//-------------------------------------------------------------------
string get_arguments_from_entry(string entry);

//-------------------------------------------------------------------
// FUNCTION: get_result_from_entry()
// Gets the truth table result from an entry
// Gets the last character as the rest are arguments
//
// PARAMETERS:
// entry (string) -> the given entry
//
// RETURNS:
// (char) -> the value of the entry
//-------------------------------------------------------------------
char get_result_from_entry(string entry);

//-------------------------------------------------------------------
// FUNCTION: populate_truth_table()
// Recursively populates a truth table based on the entries
// If an entry has a result of '0', it is skipped as it is not used in SOP
// If an entry has a result of '1', it is added to the truth table as it is used in SOP
// If an entry has a result of 'x', or "don't care", it is added to the truth table with
// value 2, as it may be useful for the combination of minterms, but is not obligatory in the SOP
// If an entry doesn't exist, it automatically gets a value of 2, or "don't care"
//
// PARAMETERS:
// tb (TruthTable&) -> the truth table which will be populated
// argument_count (int) -> total argument count (used to stop recursion)
// entries (Vector<string>) -> the given entries
// params (char[]) -> the current combination of 0s and 1s
// curr_argument (int) -> current argument count (used to stop recursion)
//
// RETURNS:
// (Function) -> the function if it exists
//
// THROWS:
// std::runtime_error -> if the function doesn't exist
//-------------------------------------------------------------------
void populate_truth_table(TruthTable &tb, int argument_count, Vector<string> entries, char params[], int curr_argument);

//-------------------------------------------------------------------
// FUNCTION: can_be_combined()
// Check if two minterms can be combined.
// Combined means that only one character in the two minterms differ
// which means it does not influence the result of the minterm, as
// both have the result of 1
// The different character gets replaced by '-', meaning "doesn't influence"
//
// PARAMETERS:
// s1 (string) -> the first minterm
// s2 (string) -> the second minterm
//
// RETURNS:
// (bool) -> can be combined or not
//
// THROWS:
// std::invalid_argument -> if the two strings have different length
//-------------------------------------------------------------------
bool can_be_combined(string s1, string s2);

//-------------------------------------------------------------------
// FUNCTION: combine()
// Combine two minterms.
// Combine means that only one character in the two minterms differ
// which means it does not influence the result of the minterm, as
// both have the result of 1
// The different character gets replaced by '-', meaning "doesn't influence"
//
// PARAMETERS:
// s1 (string) -> the first minterm
// s2 (string) -> the second minterm
//
// RETURNS:
// (string) -> the combined result
//-------------------------------------------------------------------
string combine(string s1, string s2);

//-------------------------------------------------------------------
// FUNCTION: is_minterm_included()
// Checks if a given minterm is included in a collection of implicants
//
// PARAMETERS:
// minterm (string) -> the minterm
// implicants (Queue<Implicant>) -> the collection of implicants
//
// RETURNS:
// (bool) -> is included or not
//-------------------------------------------------------------------
bool is_minterm_included(string minterm, Queue<Implicant> implicants);

//-------------------------------------------------------------------
// FUNCTION: get_possible_combinations()
// Gets all possible combinations of minterms at a given level
//
// PARAMETERS:
// original (Queue<Implicant>) -> the implicants from one level above
// level (int) -> the current level of combination (size of implicants)
//
// RETURNS:
// (Queue<Implicant>) -> the newly combined implicants
//-------------------------------------------------------------------
Queue<Implicant> get_possible_combinations(Queue<Implicant> original, int level);

//-------------------------------------------------------------------
// FUNCTION: combine_entries()
// Recursively creates all possible combinations of minterms for every level
// Ensures that every minterm in every implicant of a lower level
// is included in an implicant of a higher level
//
// PARAMETERS:
// s1 (string) -> the first minterm
// s2 (string) -> the second minterm
//
// RETURNS:
// (bool) -> can be combined or not
//-------------------------------------------------------------------
Queue<Implicant> combine_entries(Queue<Implicant> original, int level);

//-------------------------------------------------------------------
// FUNCTION: remove_dont_care_minterms_from_implicants()
// Iterates through all prime implicants and checks if any minterm in them is a
// "don't care". This means it is not needed as it doesn't influence the expression for
// the given truth table
//
// PARAMETERS:
// implicants (Queue<Implicant>) -> the prime implicants
// tb (TruthTable) -> the truth table
//
// RETURNS:
// (Queue<Implicants>) -> the prime implicants without the "don't care"s
//-------------------------------------------------------------------
Queue<Implicant> remove_dont_care_minterms_from_implicants(Queue<Implicant> implicants, TruthTable tb);

//-------------------------------------------------------------------
// FUNCTION: try_to_remove_unnecessary_implicants()
// Check if the collection of prime implicants consists of an implicant
// whose minterms are all included in the other implicant. This means the
// given implicant is not needed in the expression thus it can be removed
//
// PARAMETERS:
// implicants (Queue<Implicant>) -> the prime implicants
//
// RETURNS:
// (Queue<Implicant>) -> the prime implicants without excessive ones
//-------------------------------------------------------------------
Queue<Implicant> try_to_remove_unnecessary_implicants(Queue<Implicant> implicants);

//-------------------------------------------------------------------
// FUNCTION: convert_implicants_to_expression()
// Converts the prime implicants to a string expression, which is the
// result expression for the given truth table. Arguments are defined
// through their ASCII code, starting at 64 for 'A'.
//
// PARAMETERS:
// implicants (Queue<Implicant>) -> the prime implicants
//
// RETURNS:
// (string) -> the expression that corresponds to the truth table
//-------------------------------------------------------------------
string convert_implicants_to_expression(Queue<Implicant> implicants);

//-------------------------------------------------------------------
// FUNCTION: process_find()
// Implements the Quine-McCluskey algorithm for finding an expression
// for a given truth table
// Prints the resulted expression
//
// PARAMETERS:
// line (string) -> the find command
//
// RETURNS:
// none
//
// THROWS:
// std::invalid_argument -> if there are no 1s in the truth table
//-------------------------------------------------------------------
void process_find(string &line);

#endif //LOGICAL_EXPRESSION_INTERPRETER_FIND_HANDLER_HH
