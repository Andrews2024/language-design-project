#include "string.hpp"

template <typename Iterator>
bool String::varParse(Iterator first, Iterator last) {
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
    auto const tail = x3::lit("=") >> x3::string("\"") >> *alnum >> x3::string("\"");

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

template <typename Iterator>
bool String::arrayOfStringsParser(Iterator first, Iterator last) {
    using x3::char_;
    using x3::phrase_parse;
    using x3::ascii::space;

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