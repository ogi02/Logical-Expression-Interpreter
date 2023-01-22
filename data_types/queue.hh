#ifndef LOGICAL_EXPRESSION_INTERPRETER_QUEUE_HH
#define LOGICAL_EXPRESSION_INTERPRETER_QUEUE_HH

#include <string>
#include "function.hh"
#include "implicant.hh"
using std::string;

template <typename Object>

class Queue {
private:
    int _size = 0;
    int _capacity;
    Object* _objects;

public:
    //-------------------------------------------------------------------
    // CONSTRUCTOR: Queue()
    // Empty queue
    //
    // PARAMETERS:
    // cap (int) -> capacity of queue (default = 5)
    //-------------------------------------------------------------------
    Queue(int cap = 5);

    //-------------------------------------------------------------------
    // GETTER: size()
    // Gets the size of the vector
    //-------------------------------------------------------------------
    int size() const;

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
    // FUNCTION: first()
    // Gets the first element of the vector
    // Const prevents modification
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (Object) -> the first element of the queue
    //-------------------------------------------------------------------
    Object first() const;

    //-------------------------------------------------------------------
    // FUNCTION: is_empty()
    // Checks if queue is empty
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (bool) -> empty or not
    //-------------------------------------------------------------------
    bool is_empty();

    //-------------------------------------------------------------------
    // FUNCTION: get()
    // Gets object if it exists by comparison
    // Used for Function class
    //
    // PARAMETERS:
    // function_name (string) -> the desired function's name
    // argument_count (int) -> the desired function's argument count
    //
    // RETURNS:
    // (Object&) -> reference to the object
    //
    // THROWS:
    // std::runtime_error -> if the object doesn't exist
    //-------------------------------------------------------------------
    Object& get(string function_name, int argument_count);

    //-------------------------------------------------------------------
    // FUNCTION: get_by_function_name()
    // Gets object if it exists by function_name
    //
    // PARAMETERS:
    // function_name (string) -> the desired function's name
    //
    // RETURNS:
    // (Object&) -> reference to the object
    //
    // THROWS:
    // std::runtime_error -> if the object doesn't exist
    //-------------------------------------------------------------------
    Object& get_by_function_name(string function_name);

    //-------------------------------------------------------------------
    // FUNCTION: enqueue()
    // Pushes an element in the queue
    //
    // PARAMETERS:
    // o (const Object&) -> the object that will be enqueued
    //
    // RETURNS:
    // void
    //-------------------------------------------------------------------
    void enqueue(const Object& o);

    //-------------------------------------------------------------------
    // FUNCTION: expand()
    // Expands the queue - allocates more memory, increases capacity
    //
    // PARAMETERS:
    // new_capacity (int) -> the new_capacity
    //
    // RETURNS:
    // void
    //-------------------------------------------------------------------
    void expand(int new_capacity);

    //-------------------------------------------------------------------
    // FUNCTION: dequeue()
    // Removes and returns the first element in the queue
    //
    // PARAMETERS:
    // none
    //
    // RETURNS:
    // (Object) -> the first element
    //-------------------------------------------------------------------
    Object dequeue();
};

#endif //LOGICAL_EXPRESSION_INTERPRETER_QUEUE_HH
