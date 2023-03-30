# Syntax Guide for [LANGUAGE_NAME] >> Part 2 >> Conditionals and Loops

Loops and conditional statements use mostly the same syntax as Java/ C/ C++ to ease the transition from this language to more mainline languages. In the case of conditional statements, we have also taken inspiration from Python for comparision operators, as the use of 'and' and 'or' may be more intuitive to newer programmers.

## For Loops (Numerical)
For loops are written in the same way as Java/ C/ C++. Below is the syntax for incrementing using numbers.
```
for(integer counter = 0; counter < maximum; counter++) {
    // Do something
}
```
The first part of the for loop, `integer counter = 0`, declares an integer called counter and sets its value to 0. This is the variable we will increment for looping. The variable must be an integer, but otherwise can have any variable name that matches naming syntax and can be assigned any integer value.
The next part of the for loop, `counter < maximum`, compares the value of counter to a pre-defined integer named maximum. So long as counter is less than maximum, the loop will continue. For example, if counter is 0 and maximum is 3, the loop will execute three times (0 --> 1 --> 2). You can also use the > operator if you are decrementing counter with each loop.
The last part of the loop, `counter++`, increments the variable counter by one after each execution of the loop. You can increment by any integer value (e.g. counter += 5), and you can also decrement (decrease) by any integer (e.g. counter-- or counter -= 6).
After the for loop condition is an open bracket ({), followed by code to do something, and ended with a closed bracket (}). Anything outside these brackets is not part of the for loop.

## For Loops (Items)

```for(item in list) {
    // Do something
}