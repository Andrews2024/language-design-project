#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename Iterator>
bool arrayOfIntegersParser(Iterator, Iterator);

/*template <typename Iterator>
bool arrayOfBoolsParser(Iterator, Iterator);*/

int main(void) {
    cout << "Enter an array of integers, such as [2, 3, 7]" << endl;
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
//TODO: Add support for empty set
    using boost::spirit::x3::int_;
    using boost::spirit::x3::char_;
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

/*template <typename Iterator>
bool arrayOfBoolsParser(Iterator first, Iterator last) {
    using boost::spirit::x3::string;
    using boost::spirit::x3::char_;
    using boost::spirit::x3::phrase_parse;
    using boost::spirit::x3::ascii::space;

    bool result = phrase_parse(
        first,                          //  Start Iterator
        last,
        //  Begin grammar
        (
                '[' >> string("true")
                >> *(',' >> string("true")) >> ']'
            |   "[]" 
        ),
            //  End grammar                           //  End Iterator
        //schar_('[') >> string("true") | string("false") >> *(',' >> string("true")) >> char_(']'),   //  The Parser [true, false, false]
        space                           //  The Skip-Parser
    );
    if (first != last) // fail if we did not get a full match
        return false;
    return result;
}*/