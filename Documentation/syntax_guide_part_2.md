# Syntax Guide for [LANGUAGE_NAME] >> Part 2 >> Conditionals and Loops

Loops and conditional statements use mostly the same syntax as Java/ C/ C++ to ease the transition from this language to more mainline languages. In the case of conditional statements, we have also taken inspiration from Python for comparision operators, as the use of 'and' and 'or' may be more intuitive to newer programmers.

## Conditional statements

To execute portions of a program under specific conditions, use `if`, 'else if`, and `else` statements. Syntax for these statements is almost identical to Java and C-style languages Below is an example of each.
```
integer a = 4
integer b = 5
integer c = 6

if (a > 0) { // a greater than 0
    a = a * -1
}
else if (c < b) { // c less than b
    c = b - 1
}
else { // If neither of the above conditions are true, then
    a = b
}
```
Condtional statements are built using boolean variables, boolean comparison operators, and set operations: `<, >, <=, >=, ==, !=, AND, OR, NOT, &&, ||, and !`. AND is equivalent to &&, OR is equivalent to ||, and NOT is equivalent to !. The use of AND, OR, and NOT is similar to Python and may be more intuitive to some users. To use a boolean variable as a condition, put the name of the variable int the parentheses: `if (myBool) {}`.

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
After the for loop condition is an open bracket (`{`), followed by code to do something, and ended with a closed bracket (`}`). Anything outside these brackets is not part of the for loop.

## For Loops (Items)

It is possible to iterate through arrays by element in addition to using numerical looping. This is similar to 'for each' loops in Java and Python, as seen by the syntax.
```
for (thing in list) {
    // Do something
}
```
The loop iterates through the items in the array directly, rather than accessing items by list index. This prevents indexing errors while looping through arrays. While in the loop, the particular item can be used via the variable name used in the loop declaration. In the above example, the variable name is `thing`. The array being accessed for its items is `list`. Below is a more in-depth example of item-based looping.
```
array[3] integer integerList = [1, 2, 3]

for (num in integerList) {
    num = num * 2 // Multiply the current element by 2
}

// integerList = [2, 4, 6]
```
## While Loops

While loops are loops that occur while a certain condition is true. Below is an example of a while loop.
```
integer counter = 0

while (counter < 5) {
    // Do something
    counter++
}
```
In the parentheses is the boolean condition of the while loop. Once the condition is no longer true, the next time the program comes to the top of the loop, the loop will not be executed. To create an infinite loop, use the condition `true`.