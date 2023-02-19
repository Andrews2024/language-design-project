
### Syntax Guide for [LANGUAGE_NAME] >> Part 1 >> Variables

This language is meant to be an introductory language for people with various levels of coding experience. The basic syntax elements of this language include variables, conditionals, and loops. This first part of the guide focuses on variables.  

We chose to allow the use of either the full type name or an abbreviation to allow the user to pick between writing more concise code or writing more elaborate code that is clearer to them. The full type names may also be helpful to non-English speakers by allowing easier translation from English.  

**Mathematical Variables**

This language uses mathematical variables to represent decimal and non-decimal numbers. 

Non-decimal numbers are defined with the required keyword **integer** or can be abbreviated as **int**. These numbers are positive or negative or zero, but they must not have a decimal point. Here are two valid definitions of the number 7 in the language:

**integer** integer_1 = 7
**int** integer_2 = 7

Decimal numbers are defined with the required keyword **decimal** or can be abbreviated as **dec**. This type is the same as a double in C++ and other similar languages. We chose the keyword decimal to better convey the function of a double to newer programmers.  

These numbers are positive or negative or zero, and may or may not include a decimal point. Here are two valid definitions of the number 7.1 in the language:

**decimal** decimal_1 = 7.1
**dec** decimal_2 = 7.1

Additionally, it is possible to represent the number 7 as a decimal number in any of these ways:

**decimal** decimal_no\_point = 7
**decimal** decimal_with\_point = 7.0

**dec** dec_no\_point = 7
**dec** dec_with\_point = 7.0

Any of the above definitions are legal. The difference between integers and decimals in the language is most apparent during mathematical operations. Typical PEMDAS mathematical operations can be done using decimals, while integers run into special limits on their mathematical operations including **integer division**.

**Word Variable**

This language uses a word variable to represent different forms of text including single letters, sentences and paragraphs. This 'word' variable is defined with the required keyword **string** or can be abbreviated as **str**. Anytime a string is created within a program, the text it holds must be enclosed in "". Here are two valid definitions of the phrase: Hello!

**string** greeting_1 = "Hello!"
**str** greeting_2 = "Hello!"

A special case for the string variable is the case where the variable holds no letters in it at all. This case is called an empty string variable and is defined in these two ways:

**string** empty_string = ""
**str** empty_str = ""

C++, Java, and similar languages use a data type called a character (char). This language does not support characters, but rather uses strings of one character. This is to reduce complexity of the language.

**Truth Value Variable**

This language uses a variable to represent the states _true_ and _false_. This variable, called a boolean, is different from the string variable because the value of the variable only has TWO states. In addition, the boolean states are not read as words, but instead are read as outcomes: either the variable represents something that is true (ex: something that succeeds or matches some outcome) or something that is false (ex: something that fails or does not match some outcome). Booleans are defined using the required keyword **boolean** and the values of these variables are NOT enclosed in "".

**boolean** finished = true
**boolean** winner = false


**List Structure**

This language uses a more complex structure called an array to keep track of a list of variables. Each created array may only list one kind of variable. For instance, a list of integers may not include decimals, booleans, or strings. Arrays are created with the required keyword **array** followed by the **[]** symbol. Inside this **[]** symbol is a whole number that represents the number of items in the list. After the array keyword there is a keyword to represent the kind of variable that will be in the list (ex: **integer**/**int** or **decimal**/**dec** or **boolean** or **string**/**str**). To put initial items in the new list, place these items within the {} after the equals sign; separate items with commas. Here is an example of a list of all 12 months followed by a list of the 5 highest test scores in a class:

**array[12] string** months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

**array[5] integer** scores = [94, 96, 98, 99, 100]

_Note: The number of items in the list must be equal to the number in the []_

Arrays are dynamic in this language, meaning that items can be removed or added to the list at any time. We chose to make arrays dynamic to remove the need for arrayLists. This creates consistency across the code and removes the complexity of having two kinds of arrays.

