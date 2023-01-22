#ifndef LOGICAL_EXPRESSION_INTERPRETER_MAP_HH
#define LOGICAL_EXPRESSION_INTERPRETER_MAP_HH

#include <string>
#include "vector.hh"

using std::string;

class TruthTable {
private:
    int _size;
    Vector<string> _keys;
    Vector<int> _values;

public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: TruthTable()
    // Default constructor
    //
    // PARAMETERS:
    // none
    //-------------------------------------------------------------------
    TruthTable();

    //-------------------------------------------------------------------
    // GETTER: size()
    // Gets the size of the vector
    //-------------------------------------------------------------------
    int size() const;

    //-------------------------------------------------------------------
    // SETTER: set_size()
    // Sets the size of the vector
    //
    // PARAMETERS:
    // size (int) -> the new size for the vector
    //-------------------------------------------------------------------
    void set_size(int size);

    //-------------------------------------------------------------------
    // GETTER: keys()
    // Gets the keys of the vector
    //-------------------------------------------------------------------
    Vector<string> keys() const;

    //-------------------------------------------------------------------
    // SETTER: set_keys()
    // Sets the keys of the vector
    //
    // PARAMETERS:
    // keys (Vector<string>) -> the new keys for the vector
    //-------------------------------------------------------------------
    void set_keys(Vector<string> keys);

    //-------------------------------------------------------------------
    // GETTER: values()
    // Gets the values of the vector
    //-------------------------------------------------------------------
    Vector<int> values() const;

    //-------------------------------------------------------------------
    // SETTER: set_values()
    // Sets the values of the vector
    //
    // PARAMETERS:
    // values (Vector<int>) -> the new values for the vector
    //-------------------------------------------------------------------
    void set_values(Vector<int> values);

    //-------------------------------------------------------------------
    // OPERATOR: =
    // Assigns new value to the given truth table
    //
    // PARAMETERS:
    // o (const TruthTable&) -> the new truth table
    //
    // RETURNS:
    // (TruthTable&) -> the newly assigned truth table
    //-------------------------------------------------------------------
    TruthTable& operator=(const TruthTable& o);

    //-------------------------------------------------------------------
    // FUNCTION: update()
    // Updates value if key exists
    // Inserts value if key doesn't exist
    //
    // PARAMETERS:
    // key (string) -> the key
    // value (int) -> the value
    //
    // RETURNS:
    // none
    //-------------------------------------------------------------------
    void update(string key, int value);

    //-------------------------------------------------------------------
    // FUNCTION: get()
    // Gets value with a given key
    //
    // PARAMETERS:
    // key (string) -> the key
    //
    // RETURNS:
    // (int) -> the value or -1 if key doesn't exist
    //-------------------------------------------------------------------
    int get(string key);
};


#endif //LOGICAL_EXPRESSION_INTERPRETER_MAP_HH
