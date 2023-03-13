main: main.cpp
	g++ -Wall main.cpp -o main.out
bool_var: bool_ident.cpp
	g++ -Wall bool_ident.cpp -o main.out
dec_var: decimal_ident.cpp
	g++ -Wall decimal_ident.cpp -o main.out
str_var: string_ident.cpp
	g++ -Wall string_ident.cpp -o main.out