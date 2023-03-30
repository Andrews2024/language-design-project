#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::array;

template <typename Iterator>
bool arrayOfDoublesParser(Iterator, Iterator);
void printResult(double[],int);

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

    std::cout << "Bye... :)\n";

    return 0;
}

void printResult(double arr[], int i){
	for(size_t k = 0; k <  (size_t) i; k++){
            	printf("%f\n", arr[k]);
            }
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
