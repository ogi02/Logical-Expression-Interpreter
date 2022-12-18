#include "rpn_converter.hh"

bool is_opening_bracket(char c) {
    return c == '(';
}

bool is_closing_bracket(char c) {
    return c == ')';
}

bool is_operator(char c) {
    return c == '&' || c == '|' || c == '!';
}

bool is_operand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char op) {
    if (op == '|') {
        // lowest precedence
        return 1;
    } else if (op == '&') {
        // medium precedence
        return 2;
    } else if (op == '!') {
        // highest precedence
        return 3;
    } else {
        return 0;
    }
}

int compare_precedence(char op1, char op2) {
    int p1 = precedence(op1);
    int p2 = precedence(op2);
    if (p1 < p2) {
        // smaller precedence
        return -1;
    } else if (p1 == p2) {
        // same precedence
        return 0;
    } else {
        // higher precedence
        return 1;
    }
}

Vector<char> convert_to_rpn(string infix) {
    // stack is used to store brackets and operators
    Vector<char> stack;
    // result is used to store result
    Vector<char> result;

    // get length of infix expression
    int len = get_length(infix);

    // ensure first and last element in infix are quotes
    // otherwise the definition of the function is not correct
    if (infix[0] != '\"' || infix[len - 1] != '\"') {
        throw new runtime_error("Incorrect definition: Reason: Missing \"");
    }

    // remove quotes
    // ensure there are opening and closing bracket on the outside level wrapping the whole expression
    // because without them the operator on the highest level will be left out from the RPN expression
    remove_char_at_index(0, infix, len);
    replace_char_at_index(len - 1, ')', infix, len);
    stack.push_back('(');

    char c;
    for (int i = 0; i < get_length(infix); i++) {
        c = infix[i];
        if (is_opening_bracket(c)) {
            // gets pushed in the stack, waiting to be closed
            stack.push_back(c);
        } else if (is_closing_bracket(c)) {
            // stack should be emptied until the first opening bracket or until it's empty
            while (!stack.is_empty() && stack.top() != '(') {
                // empty all operators and put them in end result
                result.push_back(stack.pop());
            }
            // remove opening bracket from stack
            stack.pop();
        } else if (is_operand(c)) {
            // gets pushed in the result
            result.push_back(c);
        } else if (is_operator(c)) {
            // if operator has lower precedence than the operator at the top of the stack ->
            // -> pop all operators in stack and put operator in stack
            // if operator has higher precedence than the operator at the top of the stack ->
            // -> put operator in stack
            while (!stack.is_empty() && compare_precedence(c, stack.top()) < 0) {
                // pop operators from stack with higher precedence
                result.push_back(stack.pop());
            }
            // push operator in stack
            stack.push_back(c);
        }
    }

    return result;
}
