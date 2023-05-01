# Syntax Guide for [LANGUAGE_NAME] >> Part 3 >> Comments and Functions

## Comments
While writing code, it is recommended to include comments that explain the purpose of functions, how an operation works, and other important information about the overall program. This enables developers unfamiliar with the program to understand it more easily. This language uses Java/ C/ C++ syntax for comments and supports single- and multi-line comments. Below is an example.
```
// Comment explaining what this integer is for
// These comments only span one line
integer a = 9

/*A multi-line comment
It spans multiple lines and is good for longer descriptions*/
```
Any text after a `//` and on the same line is considered a comment and will be ignored by the interpreter. For multi-line comments, any text between the opening `/*` and the closing `*/` is considered part of the comment and will be ignored by the interpreter.

## Functions
Functions are useful when a given task needs to be executed multiple times throughout a program. [LANGUAGE NAME] uses syntax similar to Java and C-style languages to declare and define functions. The most notable difference is the `func` keyword at the beginning of a function declaration. This is for extra clarifty when a function is being declared versus when it is being called.
```
func int return_an_integer() {
    print("This function returns an integer and has no arguments.")
    return 0
}

func void argument_function(int number) {
    number++
    print(number)
    print("This function doesn't return anything, but it requires an integer input")
    return
}

```
Below is the syntax for calling a function.
```
int myNumber = 7
argument_function(myNumber)
```