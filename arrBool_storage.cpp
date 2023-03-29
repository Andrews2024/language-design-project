#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::array;

template <typename Iterator>
bool arrayOfBoolsParser(Iterator, Iterator);
void printResult(bool[], int);

int main(void) {
    cout << "Enter an array of doubles, such as [1.1, 2.2, 3.3]" << endl;
    cout << "Type q or Q to quit" << endl;

    string str;

    while (getline(std::cin, str))
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

    std::cout << "Bye... :)\n";

    return 0;
}

void printResult(bool arr[], int i){
	for(size_t k = 0; k <  (size_t) i; k++){
        cout << arr[k] << ", ";
    }
    cout << endl;
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

