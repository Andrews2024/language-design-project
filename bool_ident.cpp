#include <iostream>
#include <string>

#include <boost/spirit/home/x3.hpp>

namespace x3 = boost::spirit::x3;

using x3::alnum;
using x3::alpha;
using x3::lexeme;

using std::cout;
using std::endl;
using boost::spirit::x3::string;
using boost::spirit::x3::char_;

template <typename Iterator>
bool varParse(Iterator, Iterator);

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

int main(void) {
    cout << "Enter variables" << endl;
    cout << "Type q or Q to quit" << endl;

    std::string str;

    while (getline(std::cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        if (varParse(str.begin(), str.end()))
        {
            cout << "Parsing succeeded\n";
        }
        else
        {
            cout << "Parsing failed\n";
        }
    }

    std::cout << "Bye... :)\n";

    return 0;
}

template <typename Iterator>
bool varParse(Iterator first, Iterator last) {
    using boost::spirit::x3::phrase_parse;
    
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