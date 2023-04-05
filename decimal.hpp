#ifndef DECIMAL_H
#define DECIMAL_H

#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::array;
using std::cin;

namespace x3 = boost::spirit::x3;

using x3::alnum;
using x3::alpha;
using x3::lexeme;
using x3::char_;
using x3::double_;

class Decimal {
    public:
        template <typename Iterator>
        bool arrayOfDecimalsParser(Iterator, Iterator);
        void storeArray(string str);
        void printResult(double[],int);
        template <typename Iterator>
        bool varParse(Iterator, Iterator);
        void storeVar(string str);
};

#endif