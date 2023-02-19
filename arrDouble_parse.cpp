#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename Iterator>
bool arrayOfDoublesParser(Iterator, Iterator);

int main(void) {
    cout << "Enter an array of doubles, such as [1.1, 2.2, 3.3]" << endl;
    cout << "Type q or Q to quit" << endl;

    string str;

    while (getline(std::cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        if (arrayOfDoublesParser(str.begin(), str.end()))
        {
            cout << "Parsing succeeded\n";
        }
        else
        {
            std::cout << "Parsing failed\n";
        }
    }

    std::cout << "Bye... :)\n";

    return 0;
}

template <typename Iterator>
bool arrayOfDoublesParser(Iterator first, Iterator last) {
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
