# Logical-Expression-Interpreter
Term task for Algorithms course in 3rd semester in TU-Sofia.

## Task
The requirements for the task are located in `Task.docx` but are only available in Bulgarian.

## Supports
1. Defining boolean functions with arguments
2. Solving boolean function with given values
3. Generating a truth table for a given function
4. Finding an expression for a given truth table using Quine-McCluskey algorithm
5. Saving functions to `.csv` files
6. Reading functions from `.csv` files
7. Drawing a binary of a function's definition or solution with given values

## Requirements
The following project requires the library `<graphics.h>` for C++. The required libraries are located in
`requirements` folder. Credits to [Codewar](http://www.youtube.com/c/codewar) for the libraries and the 
explanation on how to set them up.

The project also requires `make` to be compiled.

## Run
Download the source code of the project and navigate to the main folder.

Execute on Windows:
```commandline
make
.\lei.exe
```

Execute on Linux:
```commandline
make
./lei
```

Delete executables:
```commandline
make clean
```

## Test commands
```text
    DEFINE   func1(a,  b): "a & b "  -> expected to trim spaces
    
DEFINE func1(): "a & b"         -> missing arguments
DEFINE func1(a): "a & c"        -> "c" is undefined
DEFINE func1() "a & b"          -> missing :
DEFINE func1): "a & b"          -> missing (
DEFINE func1(a, b: "a & b"      -> missing )
DEFINE func1(a, b): a & b"      -> missing " in the beginning of the expression
DEFINE func1(a, b): "a & b      -> missing " in the end of the expression

DEFINE func2(a, b, c): "func1(a, b) | c"        -> uses "func1"
DEFINE func3(a, b, c): "func1(a, b, c) | c"     -> "func1" is not defined with 3 arguments

DEFINE func4(a,b): "(a|!b)|(!a&!b)&(a&b)"           -> longer function
DEFINE func5(a,b): "(a|b)|(a&b)&(a&b)"              -> longer function
DEFINE func6(a,b): "(a|b)&(!a&b)|(!a&b)|(a|!b)"     -> longer function

SOLVE func1(1, 0)       -> Result: 0
SOLVE func2(1, 0, 1)    -> Result: 1

SOLVE func6(1, 0, 1)    -> "func6" is not defined with 3 arguments
SOLVE func7(1, 0)       -> "func7" is not defined

DEFINE func8(a, b, c): "a | b & !c"     -> used for finding truth table
ALL func8

FIND 0001,0010,0101,0110,1000,1010,1101,1111    -> Expected result: "A & B | !A & !C"

FIND 00000,00010,00100,00110,01001,01010,01100,01110,10001,1001x,10101,10111,11001,11010,1110x,11111    -> Expected result: "B & !C & !D | A & !D | A & C"
```

## Known issues
When executing the code, don't close the windows with the drawings of the binary trees, just minimize them,
because closing them causes the program to terminate.
