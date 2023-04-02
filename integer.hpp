#ifndef INTEGER_H
#define INTEGER_H

#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

class Integer {
    public:
        template <typename Iterator>
        bool arrayOfIntegersParser(Iterator first, Iterator last);
        void storeArray(string str);
        void printResult(int[],int);
};

#endif