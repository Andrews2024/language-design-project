#include "decimal.hpp"

template <typename Iterator>
bool Decimal::arrayOfDecimalsParser(Iterator first, Iterator last) {
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

void Decimal::printResult(double arr[], int i){
	for(size_t k = 0; k <  (size_t) i; k++){
            	printf("%f\n", arr[k]);
            }
}
void Decimal::storeArray(string str) {
    while (getline(cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        if (arrayOfDecimalsParser(str.begin(), str.end()))
        {
            cout << "Parsing succeeded\n";
            size_t i;
            for(i = 0; i < str.length(); i++){
                if(str[i] == ',' || str[i] == ']'){
                    i++;
                }
            }
            double arr_result[i];
            string c = "";
            i = 0;
            for (size_t j = 1; j < str.length(); j++){
                if(str[j] != ',' && str[j] != ']'){
                    c = c + str[j];
                }
                if(str[j] == ',' || str[j] == ']'){
                    arr_result[i] = atof(c.c_str());
                    c = "";
                    i++;
                }
            
            }
            printResult(arr_result,i);
        }
        else
        {
            std::cout << "Parsing failed\n";
        }
    }
}

template <typename Iterator>
bool Decimal::varParse(Iterator first, Iterator last) {
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

void Decimal::storeVar(string str) {
    bool numStart = false;
    if (varParse(str.begin(), str.end()))
    {
        cout << "Parsing succeeded\n";
        string c = "";
        for(size_t i = 0; i < str.length(); i++){
            if(str[i] == '='){
                i += 2;
                numStart = true;
            }
            if(numStart){
                c = c + str[i];
            }
            }
            double d = atof(c.c_str());
            cout << d;
    }
    else
    {
        cout << "Parsing failed\n";
    }
}
