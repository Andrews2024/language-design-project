#include <boost/spirit/home/x3.hpp>
#include <iostream>
#include <fstream>

#include "boolean.hpp"
#include "integer.hpp"
#include "decimal.hpp"
#include "string.hpp"

using std::cout;
using std::endl;
using std::ifstream;

int main(void) {
    cout << "Reading file..." << endl;

    std::string str;
    ifstream file("ExampleCode/VARIABLE_READING_TEST.txt");

    while(getline(file, str)) {
        cout << str << endl;
    }
    
    return 0;
}
