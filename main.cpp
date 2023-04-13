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

int main(void) {
    Decimal decClass;
    StringVar strClass;
    Boolean boolClass;
    Integer intClass;

    cout << "Reading file..." << endl;

    std::string str;
    ifstream file("ExampleCode/VARIABLE_READING_TEST.txt");

    while(getline(file, str)) {
        if(decClass.varParse(str.begin(), str.end())) { continue; }
        else if(strClass.varParse(str.begin(), str.end())) { continue; }
        else if(boolClass.varParse(str.begin(), str.end())) { continue; }
        else if(intClass.varParse(str.begin(), str.end())) { continue; }
        else {
            cout << "SyntaxError: " << str << endl;
            return 1;
        }
    }
    
    return 0;
}
