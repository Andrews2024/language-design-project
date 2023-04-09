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

class StringVar {
    public:
        template <typename Iterator>
        bool varParse(Iterator first, Iterator last);
        
        template <typename Iterator>
        bool arrayOfStringsParser(Iterator first, Iterator last);
};

#endif