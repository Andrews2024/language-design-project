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
        bool arrayOfDecimalsParser(Iterator first, Iterator last) {
            using boost::spirit::x3::double_;
            using boost::spirit::x3::char_;
            using boost::spirit::x3::phrase_parse;
            using boost::spirit::x3::ascii::space;

            bool result = phrase_parse(
                first,                          //  Start Iterator
                last,                           //  End Iterator
                char_('[') >> double_ >> *(',' >> double_) >> char_(']'),   //  The Parser
                space                           //  The Skip-Parser
            );
            if (first != last) // fail if we did not get a full match
                return false;
            return result;
        }
        
        void storeArray(string str);
        void printResult(double[],int);
        
        template <typename Iterator>
        bool varParse(Iterator first, Iterator last) {
            //Only allows keyword 'dec' first
            auto const keyword = x3::lit("dec");
            auto const keyword_with_space = x3::lit("dec ");
            auto const keyword2 = x3::lit("decimal");
            auto const keyword2_with_space = x3::lit("decimal ");

            //Any identifier allowed with the first character alphabetical; use lexeme to separate var defs with spaces
            auto const name = lexeme[(alpha >> *alnum)] - keyword;
            auto const name2 = lexeme[(alpha >> *alnum)] - keyword2;
            auto const var = keyword_with_space >> name;
            auto const var2 = keyword2_with_space >> name2;
            auto const tail = x3::lit("=") >> double_;

            //Any combinations of variables to parse
            auto const input_vars = +((var | var2) >> -tail);

            using x3::phrase_parse;
            
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
        
        void storeVar(string str);
};

#endif