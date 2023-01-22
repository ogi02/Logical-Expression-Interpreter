#include "implicant.hh"

Implicant::Implicant() { }

Implicant::Implicant(int size, Vector<string> minterms, string combined)
    : _size(size), _minterms(minterms), _combined(combined) { }

int Implicant::size() const {
    return _size;
}

Vector<string> Implicant::minterms() const {
    return _minterms;
}

string Implicant::combined() const {
    return _combined;
}
