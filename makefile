main: main.cpp
	g++ -Wall main.cpp -o main.out
dec_var: decimal_ident.cpp
	g++ -Wall decimal_ident.cpp -o main.out
str_var: string_ident.cpp
	g++ -Wall string_ident.cpp -o main.out
bool_arr: arrBool_storage.cpp
	g++ -Wall arrBool_storage.cpp -o main.out