#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// template <typename Iterator>
// bool arrayOfIntegersParser(Iterator, Iterator);
template <typename Iterator>
bool arrayOfStringsParser(Iterator, Iterator);

template <typename Iterator>
bool arrayOfDoublesParser(Iterator, Iterator);

template <typename Iterator>
bool arrayOfBoolsParser(Iterator, Iterator);

int main(void) {
    // cout << "Enter and array of strings such as ['a','b','c']"<< endl;//integers, such as [1, 2, 3]" << endl;
    cout << "Enter an array of booleans, such as [true, false]" << endl;
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

// template <typename Iterator>
// bool arrayOfIntegersParser(Iterator first, Iterator last) {
//     using boost::spirit::x3::int_;
//     using boost::spirit::x3::char_;
//     using boost::spirit::x3::phrase_parse;
//     using boost::spirit::x3::ascii::space;

//     bool result = phrase_parse(
//         first,                          //  Start Iterator
//         last,                           //  End Iterator
//         char_('[') >> int_ >> *(',' >> int_) >> char_(']'),   //  The Parser
//         space                           //  The Skip-Parser
//     );
//     if (first != last) // fail if we did not get a full match
//         return false;
//     return result;
// }

// template <typename Iterator>
// bool arrayOfCharsParser(Iterator first, Iterator last) {
//     using boost::spirit::x3::int_;
//     using boost::spirit::x3::char_;
//     using boost::spirit::x3::phrase_parse;
//     using boost::spirit::x3::ascii::space;

//     bool result = phrase_parse(
//         first,                          //  Start Iterator
//         last,                           //  End Iterator
//         char_('[') >> (char_) >> *(',' >> char_) >> char_(']'),   //  The Parser
//         space                           //  The Skip-Parser
//     );
//     if (first != last) // fail if we did not get a full match
//         return false;
//     return result;
// }

template <typename Iterator>
bool arrayOfIntegersParser(Iterator first, Iterator last) {
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

template <typename Iterator>
bool arrayOfBoolsParser(Iterator first, Iterator last) {
    using boost::spirit::x3::string;
    using boost::spirit::x3::char_;
    using boost::spirit::x3::phrase_parse;
    using boost::spirit::x3::ascii::space;

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

template <typename Iterator>
bool arrayOfStringsParser(Iterator first, Iterator last) {
    using boost::spirit::x3::int_;
    using boost::spirit::x3::char_;
    using boost::spirit::x3::phrase_parse;
    using boost::spirit::x3::ascii::space;

    //auto const quoted_string = boost::spirit::x3::lexeme['"' >> +(char_ - '"') >> '"'];

    bool result = phrase_parse(
        first,                          //  Start Iterator
        last,                           //  End Iterator
        char_('[') >> char_('\'') >> *(char_ - char('\'')) >> char_('\'') >> *(',' >> char_('\'') >> *(char_ - char('\'')) >> char_('\''))>> char_(']'),   //  The Parser
        space                           //  The Skip-Parser
    );
    if (first != last) // fail if we did not get a full match
        return false;
    return result;
}
