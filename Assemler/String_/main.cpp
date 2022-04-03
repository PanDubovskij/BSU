#include <iostream>

extern "C" int _stdcall FindWord(char* str, char* sub_str);

int main() { 
 char str[] = "goodbye Hello world";
 char sub_str[] = "Hello";
 std::cout << FindWord(str,sub_str);
}