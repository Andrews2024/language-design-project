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