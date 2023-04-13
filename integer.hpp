#ifndef INTEGER_H
#define INTEGER_H

#include <boost/spirit/home/x3.hpp>
#include <iostream>

namespace x3 = boost::spirit::x3;
using x3::int_;

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Integer {
    public:
        template <typename Iterator>
        bool arrayOfIntegersParser(Iterator first, Iterator last) {
            
            using boost::spirit::x3::phrase_parse;
            using boost::spirit::x3::ascii::space;

            bool result = phrase_parse(
                first,                          //  Start Iterator
                last,                           //  End Iterator
                (
                        '[' >> int_
                        >> *(',' >> int_) >> ']'
                    |   "[]"
                ),
                space                           //  The Skip-Parser
            );
            if (first != last) // fail if we did not get a full match
                return false;
            return result;
        }

        template <typename Iterator>
        bool varParse(Iterator first, Iterator last) {
            using x3::string;
            //Only allows keyword 'bool' first
            auto const keyword_int = x3::lit("int");
            auto const keyword_int_with_space = x3::lit("int ");
            auto const keyword_integer = x3::lit("integer");
            auto const keyword_integer_with_space = x3::lit("integer ");

            //Any identifier allowed with the first character alphabetical; use lexeme to separate var defs with spaces
            auto const name = lexeme[(alpha >> *alnum)] - keyword_int;
            auto const name2 = lexeme[(alpha >> *alnum)] - keyword_integer;
            auto const var = keyword_int_with_space >> name;
            auto const var2 = keyword_integer_with_space >> name2;
            auto const tail = x3::lit("=") >> int_;

            //Any combinations of variables to parse
            auto const input_vars = +((var | var2) >> -tail);

            // The actual parsing and separation
            bool result = phrase_parse(
                first,                          //  Start Iterator
                last,                           //  End Iterator
                input_vars,                     //  The Parser
                x3::ascii::space                //  The Skip-Parser
            );
            if (first != last) // fail if we did not get a full match
                return false;
            
            return result;
        }

        void storeArray(string str);
        void printResult(int[],int);
};

#endif