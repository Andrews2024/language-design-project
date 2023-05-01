#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <boost/spirit/home/x3.hpp>

namespace x3 = boost::spirit::x3;

using x3::alnum;
using x3::alpha;
using x3::punct;
using x3::lexeme;
using x3::char_;
using x3::phrase_parse;
using x3::ascii::space;

using std::cout;
using std::cin;
using std::endl;

class StringVar {
    public:

        template <typename Iterator>
        bool varParse(Iterator first, Iterator last) {
            //Only allows keyword 'str' first
            auto const keyword_str = x3::lit("str");
            auto const keyword_str_with_space = x3::lit("str ");
            auto const keyword_string = x3::lit("string");
            auto const keyword_string_with_space = x3::lit("string ");
            
            //Any identifier allowed with the first character alphabetical; use lexeme to separate var defs with spaces
            auto const name = lexeme[(alpha >> *alnum)] - keyword_str;
            auto const name2 = lexeme[(alpha >> *alnum)] - keyword_string;
            auto const var = keyword_str_with_space >> name;
            auto const var2 = keyword_string_with_space >> name2;
            auto const tail = x3::lit("=") >> string("\"") >> *(char_ - '"') >> string("\"");

            //Any combinations of variables to parse
            auto const input_vars = +((var | var2) >> -tail);

            using x3::phrase_parse;
            
            bool result = phrase_parse(
                first,                          //  Start Iterator
                last,                           //  End Iterator
                input_vars,                     //  The Parser
                space                //  The Skip-Parser
            );
            if (first != last) // fail if we did not get a full match
                return false;
            return result;
        }
        
        template <typename Iterator>
        bool arrayOfStringsParser(Iterator first, Iterator last) {
            //auto const quoted_string = boost::spirit::x3::lexeme['"' >> +(char_ - '"') >> '"'];

            bool result = phrase_parse(
                first,                          //  Start Iterator
                last,                           //  End Iterator
                char_('[') >> char_('"') >> *(char_ - '"') >> char_('"') >>  // First string
                *(',' >> char_('"') >> *(char_ - '"') >> char_('"')) >> char_(']'),   //  The Parser
                space                           //  The Skip-Parser
            );
            if (first != last) // fail if we did not get a full match
                return false;
            return result;
        }

        template <typename Iterator>
        bool singleCommentParse(Iterator first, Iterator last) {
        
            bool result = phrase_parse(
                first,                          //  Start Iterator
                last,                           //  End Iterator
                x3::string("//") >> *char_,                        //  The Parser
                space                           //  The Skip-Parser
            );
            if (first != last) // fail if we did not get a full match
                return false;
            return result;
        }

        void storeArray(std::string str);
        void printResult(std::string array[], int i);
};

#endif