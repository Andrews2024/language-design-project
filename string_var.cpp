#include "string_var.hpp"

void StringVar::storeArray(std::string str) {
    if (arrayOfStringsParser(str.begin(), str.end()))
    {
        cout << "Parsing succeeded\n";
        size_t i;
        for(i = 0; i < str.length(); i++){ // Count number of elements in array
            if(str[i] == ',' || str[i] == ']'){
                i++;
            }
        }
        
        std::string arr_result[i];
        std::string c = "";
        i = 0;
        bool inString = false;
        
        for (size_t j = 1; j < str.length(); j++){ // For character in input
            if(str[j] == '"' && !inString) { // If starting a new string
                inString = true;
                continue;
            }
            
            else if(str[j] == '"' && inString) { // If ending a string
                arr_result[i] = c;
                c = "";
                i++;
                inString = false;
            }
            
            else if(str[j] == ']' && !inString){ // If at end of array
                break;
            }
            
            else if(!inString) {
                continue; // Skip commas and spaces between inputs
            }
            
            else {
                c = c + str[j];
            }
        
        }
        printResult(arr_result, i);
    }
    else
    {
        cout << "Parsing failed\n";
    }
}

void StringVar::printResult(std::string arr[], int i){
	for(size_t k = 0; k <  (size_t) i; k++) {
        cout << arr[k] << endl;
    }

    cout << endl;
}
