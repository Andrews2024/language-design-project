#ifndef BOOL_H
#define BOOL_H

#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace x3 = boost::spirit::x3;
using x3::alnum;
using x3::alpha;
using x3::lexeme;
using x3::phrase_parse;
using x3::char_;

class Boolean {
    public:
        template <typename Iterator>
        bool arrayOfBoolsParser(Iterator first, Iterator last);

        template <typename Iterator>
        bool varParse(Iterator, Iterator);

        void storeArray(string str);
        void printResult(bool[],int);
};

#endif