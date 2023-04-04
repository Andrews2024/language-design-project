#ifndef BOOL_H
#define BOOL_H

#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
namespace x3 = boost::spirit::x3;

class Boolean {
    public:
        template <typename Iterator>
        bool arrayOfBoolsParser(Iterator first, Iterator last);
        void storeArray(string str);
        void printResult(bool[],int);

};

#endif