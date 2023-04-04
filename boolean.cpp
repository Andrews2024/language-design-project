#include "boolean.hpp"

template <typename Iterator>
bool Boolean::arrayOfBoolsParser(Iterator first, Iterator last) {
    using x3::string;
    using x3::char_;
    using x3::phrase_parse;
    using x3::ascii::space;

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

void Boolean::printResult(bool arr[], int i){
	for(size_t k = 0; k <  (size_t) i; k++){
        cout << arr[k] << ", ";
    }
    cout << endl;
}

void Boolean::storeArray(string str) {
    while (getline(cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        if (arrayOfBoolsParser(str.begin(), str.end()))
        {
            cout << "Parsing succeeded\n";
            size_t i;
            for(i = 0; i < str.length(); i++){ // Get size to allocate for array
            	if(str[i] == ',' || str[i] == ']'){
            		i++;
            	}
            }
            bool arr_result[i];
            string c = "";
            i = 0;
            for (size_t j = 1; j < str.length(); j++){ // Build up string char by char
            	if(str[j] != ',' && str[j] != ']'){
            		c = c + str[j];
            	}
            	if(str[j] == ',' || str[j] == ']'){ // Delimiting character
                    if(c.compare("true") == 0) {
                        arr_result[i] = true; // 1
                    }
                    else {
                        arr_result[i] = false; // 0
                    }
            		c = ""; // Reset current string value
            		i++;
            	}
            
            }
            printResult(arr_result, i);
        }
        else
        {
            std::cout << "Parsing failed\n";
        }
    }
}

template <typename Iterator>
bool Boolean::varParse(Iterator first, Iterator last) {
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

    // The actual parsing and separation
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