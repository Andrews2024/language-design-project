#include "decimal.hpp"
#include "storage.h"

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

void Decimal::storeVar(string str) {
    bool numStart = false;
    bool nameStart = false;
    if (varParse(str.begin(), str.end()))
        {
            cout << "Parsing succeeded\n";
            string c = "";
            string n = "";
            for(size_t i = 0; i < str.length(); i++){
            	if(str[i] == ' ' && !nameStart){
            		i += 1;
            		nameStart = true;
            	}
            	if(str[i] == '='){
            		i += 2;
            		numStart = true;
            	}
            	if(nameStart && !numStart){
            		if(str[i] != ' '){
            			n += str[i];
            		}
            	}
            	if(numStart){
            		c += str[i];
            	}
             }
             double d = atof(c.c_str());
             cout << d;
             cout << n;
             
             //AST implementation within parser
             def_t* def1 = var_def_constructor(kw_to_type("dec"), n.c_str(), num_lit_constructor(d));       
        }
        else
        {
            cout << "Parsing failed\n";
        }
}

int main(){return 0;}
