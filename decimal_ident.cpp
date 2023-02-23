#include <iostream>
#include <string>

#include <boost/spirit/home/x3.hpp>

namespace x3 = boost::spirit::x3;

using x3::alnum;
using x3::alpha;


using std::cout;
using std::endl;
using std::string;
using boost::spirit::x3::char_;

template <typename Iterator>
bool varParse(Iterator, Iterator);

//Only allows keyword 'dec' first
auto const keyword = x3::lit("dec");
auto const keyword_with_space = x3::lit("dec ");

//Any identifier allowed with the first character alphabetical; use lexeme to separate var defs with spaces
auto const name = (alpha >> *alnum) - keyword;
auto const var = keyword_with_space >> name;

//Any combinations of variables to parse; +var also works for the lexeme approach
auto const input_vars = var >> *(',' >> var);

int main(void) {
    cout << "Enter variables" << endl;
    cout << "Type q or Q to quit" << endl;

    string str;

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





