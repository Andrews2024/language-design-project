#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <boost/spirit/home/x3.hpp>

namespace x3 = boost::spirit::x3;

using x3::alnum;
using x3::alpha;
using x3::lexeme;

using std::cout;
using std::endl;

class String {
    public:
        template <typename Iterator>
        bool varParse(Iterator, Iterator);
        
        template <typename Iterator>
        bool arrayOfStringsParser(Iterator first, Iterator last);
};

#endif