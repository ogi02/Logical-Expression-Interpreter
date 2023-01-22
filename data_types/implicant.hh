#ifndef LOGICAL_EXPRESSION_INTERPRETER_IMPLICANT_HH
#define LOGICAL_EXPRESSION_INTERPRETER_IMPLICANT_HH

#include <string>
#include "vector.hh"
using namespace std;

class Implicant {
private:
    int _size;
    Vector<string> _minterms;
    string _combined;

public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: Implicant()
    // Default constructor
    //
    // PARAMETERS:
    // none
    //-------------------------------------------------------------------
    Implicant();

    //-------------------------------------------------------------------
    // CONSTRUCTOR: Implicant()
    // New implicant
    //
    // PARAMETERS:
    // size (int) -> size of the implicant
    // minterms (Vector<string>) -> the minterms of the implicant
    // combined (string) -> the combined value of the minterms
    //-------------------------------------------------------------------
    Implicant(int size, Vector<string> minterms, string combined);

    //-------------------------------------------------------------------
    // GETTER: size()
    // Gets the size of the implicant
    //-------------------------------------------------------------------
    int size() const;

    //-------------------------------------------------------------------
    // GETTER: minterms()
    // Gets the minterms of the implicant
    //-------------------------------------------------------------------
    Vector<string> minterms() const;

    //-------------------------------------------------------------------
    // GETTER: combined()
    // Gets the combined value of the implicant
    //-------------------------------------------------------------------
    string combined() const;
};

#endif //LOGICAL_EXPRESSION_INTERPRETER_IMPLICANT_HH
