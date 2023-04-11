#include "integer.hpp"

Integer::Integer(){}

void Integer::printResult(int arr[], int i){
	for(size_t k = 0; k <  (size_t) i; k++) {
        printf("%d\n", arr[k]);
    }

    cout << endl;
}

void Integer::storeArray(string str) {
    while (getline(cin, str)) { // While there are characters in buffer to parse
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        if (arrayOfIntegersParser(str.begin(), str.end()))
        {
            cout << "Parsing succeeded\n";
            size_t i;
            for(i = 0; i < str.length(); i++){
            	if(str[i] == ',' || str[i] == ']'){
            		i++;
            	}
            }
            int arr_result[i];
            string c = "";
            i = 0;
            for (size_t j = 1; j < str.length(); j++){
            	if(str[j] != ',' && str[j] != ']'){
            		c = c + str[j];
            	}
            	if(str[j] == ',' || str[j] == ']'){
            		arr_result[i] = std::stoi(c.c_str());
            		c = "";
            		i++;
            	}
            
            }
            printResult(arr_result,i);
        }
        else
        {
            cout << "Parsing failed\n";
        }
    }
}