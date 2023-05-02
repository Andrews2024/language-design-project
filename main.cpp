#include <boost/spirit/home/x3.hpp>
#include <iostream>
#include <fstream>

#include "boolean.hpp"
#include "integer.hpp"
#include "decimal.hpp"
#include "string_var.hpp"

using std::cout;
using std::endl;
using std::ifstream;

Decimal decClass;
StringVar strClass;
Boolean boolClass;
Integer intClass;

int file_syntax_valid(void) {
    cout << "Reading file..." << endl;

    std::string str;
    ifstream file("ExampleCode/VARIABLE_READING_TEST.txt");

    while(getline(file, str)) {
        if (strClass.singleCommentParse(str.begin(), str.end())) { continue; }
        else if(decClass.varParse(str.begin(), str.end())) { continue; }
        else if(strClass.varParse(str.begin(), str.end())) { continue; }
        else if(boolClass.varParse(str.begin(), str.end())) { continue; }
        else if(intClass.varParse(str.begin(), str.end())) { continue; }
        else {
            cout << "SyntaxError: " << str << endl;
            return 1;
        }
        /*
        TODO: Multi-line comment parsing
        * If line is beginning of mutli-line comment, flip on a boolean that we are waiting fo the end of the comment
        * If comment starts and ends on same line, continue
        */
    }
    cout << "File read successfully!" << endl;
    return 0;
}

int terminal_debug(void) {
    std::string str;
    cout << "Input string variables" << endl;
    cout << "Enter q or Q to quit" << endl;

    while (getline(cin, str)) { // While there are characters in buffer to parse
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;
        
        strClass.storeArray(str);
    }

    std::cout << "Bye... :)\n";

    return 0;
}

int main(void) {
    bool file_read = true;
    
    if (file_read) {
        file_syntax_valid();
    }
    else {
        terminal_debug();
    }
    return 0;
}
