#ifndef BOOL_H
#define BOOL_H

#include <boost/spirit/home/x3.hpp>
#include <iostream>


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
        bool arrayOfBoolsParser(Iterator first, Iterator last) {
            using x3::string;
            using x3::char_;
            using x3::phrase_parse;
            using x3::ascii::space;

            bool result = phrase_parse(
                first,                          //  Start Iterator
                last,
                //  Begin grammar -> parenthesis because there are options for valid parses
                (
                        '[' >> (string("true") | string("false"))
                        >> *(',' >> (string("true") | string("false"))) >> ']'
                    |   "[]"  //empty set is valid
                ), 
                //End grammar
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
            auto const keyword_bool = x3::lit("bool");
            auto const keyword_bool_with_space = x3::lit("bool ");
            auto const keyword_boolean = x3::lit("boolean");
            auto const keyword_boolean_with_space = x3::lit("boolean ");

            //Any identifier allowed with the first character alphabetical; use lexeme to separate var defs with spaces
            auto const name = lexeme[(alpha >> *alnum)] - keyword_bool;
            auto const name2 = lexeme[(alpha >> *alnum)] - keyword_boolean;
            auto const var = keyword_bool_with_space >> name;
            auto const var2 = keyword_boolean_with_space >> name2;
            auto const tail = x3::lit("=") >> (string("true") | string("false"));

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

        void storeArray(std::string str);
        void printResult(bool[],int);
};

#endif