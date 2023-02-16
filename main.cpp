#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename Iterator>
bool arrayOfIntegersParser(Iterator, Iterator);

int main(void) {
    cout << "Enter an array of integers, such as [1, 3, 5]" << endl;
    cout << "Type q or Q to quit" << endl;

    string str;

    while (getline(std::cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        if (arrayOfIntegersParser(str.begin(), str.end()))
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
bool arrayOfIntegersParser(Iterator first, Iterator last) {
    using boost::spirit::x3::int_;
    using boost::spirit::x3::char_;
    using boost::spirit::x3::phrase_parse;
    using boost::spirit::x3::ascii::space;

    bool result = phrase_parse(
        first,                          //  Start Iterator
        last,                           //  End Iterator
        char_('[') >> int_ >> *(',' >> int_) >> char_(']'),   //  The Parser [x, y, z]
        space                           //  The Skip-Parser
    );
    if (first != last) // fail if we did not get a full match
        return false;
    return result;
}