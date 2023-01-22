#ifndef LOGICAL_EXPRESSION_INTERPRETER_VECTOR_HH
#define LOGICAL_EXPRESSION_INTERPRETER_VECTOR_HH
#include <string>
#include "../nodes/node.hh"
using std::string;

template <typename Object>

class Vector {
private:
    int _size = 0;
    int _capacity;
    Object* _objects;

public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: Vector()
    // Empty vector
    //
    // PARAMETERS:
    // cap (int) -> capacity of vector (default = 5)
    //-------------------------------------------------------------------
    Vector(int cap = 5);

    //-------------------------------------------------------------------
    // CONSTRUCTOR: Vector()
    // Vector from string
    //
    // PARAMETERS:
    // from (string) -> the string from which a vector will be created
    // len (int) -> length of string
    //-------------------------------------------------------------------
    Vector(string from, int len);

    //-------------------------------------------------------------------
    // OPERATOR: []
    // Gets element at given index
    //
    // PARAMETERS:
    // index (int) -> the given index
    //
    // RETURNS:
    // (Object&) -> the object at the given index
    //-------------------------------------------------------------------
    Object& operator[](int index) const;

    //-------------------------------------------------------------------
    // GETTER: size()
    // Gets the size of the vector
    //-------------------------------------------------------------------
    int size() const;

    //-------------------------------------------------------------------
    // FUNCTION: top()
    // Gets the top element of the vector
    // Const prevents modification
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (Object) -> the top element of the vector
    //-------------------------------------------------------------------
    Object top() const;

    //-------------------------------------------------------------------
    // FUNCTION: is_empty()
    // Checks if vector is empty
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (bool) -> empty or not
    //-------------------------------------------------------------------
    bool is_empty();

    //-------------------------------------------------------------------
    // FUNCTION: contains()
    // Checks if vector contains a given element
    //
    // PARAMETERS:
    // o (Object) -> the desired object
    //
    // RETURNS:
    // (bool) -> contains or not
    //-------------------------------------------------------------------
    bool contains(Object o);

    //-------------------------------------------------------------------
    // FUNCTION: get_index_of()
    // Gets the index of a given element if it exists
    //
    // PARAMETERS:
    // o (Object) -> the desired object
    //
    // RETURNS:
    // (int) -> index if exists, -1 if it doesn't
    //-------------------------------------------------------------------
    int get_index_of(Object o);

    //-------------------------------------------------------------------
    // FUNCTION: push_back()
    // Pushes an element in the stack
    //
    // PARAMETERS:
    // o (const Object&) -> the object that will be pushed
    //
    // RETURNS:
    // void
    //-------------------------------------------------------------------
    void push_back(const Object& o);

    //-------------------------------------------------------------------
    // FUNCTION: expand()
    // Expands the vector - allocates more memory, increases capacity
    //
    // PARAMETERS:
    // new_capacity (int) -> the new_capacity
    //
    // RETURNS:
    // void
    //-------------------------------------------------------------------
    void expand(int new_capacity);

    //-------------------------------------------------------------------
    // FUNCTION: pop()
    // Removes and returns the top element in the vector
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (Object) -> the top element
    //-------------------------------------------------------------------
    Object pop();

    //-------------------------------------------------------------------
    // FUNCTION: to_string()
    // Converts the elements of the vector into one string
    // Implemented only for Vector<char>
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (string) -> the string representation of the vector
    //-------------------------------------------------------------------
    string to_string();
};


#endif //LOGICAL_EXPRESSION_INTERPRETER_VECTOR_HH
