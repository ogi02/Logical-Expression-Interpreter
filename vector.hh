#ifndef LOGICAL_EXPRESSION_INTERPRETER_VECTOR_HH
#define LOGICAL_EXPRESSION_INTERPRETER_VECTOR_HH
using std::string;
template <typename Object>

class Vector {
private:
    int _size;
    int _capacity;
    Object* _objects;

public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: Vector()
    // Empty vector
    //
    // PARAMETERS:
    // len (int) -> length of vector (default = 5)
    //-------------------------------------------------------------------
    Vector(int len = 5);

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
    Object& operator[] (int index) const;

    //-------------------------------------------------------------------
    // FUNCTION: size() const
    // Gets the size of the vector
    // Const prevents modification
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (int) -> the size of the vector
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
    // Self explanatory
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (bool) -> empty or not
    //-------------------------------------------------------------------
    bool is_empty();

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
