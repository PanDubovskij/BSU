#include <iostream>

extern "C" int _fastcall CountLength(char* str);
extern "C" int _stdcall FindIndex(char* str,char let);
extern "C" int _stdcall FindIndexFromBeginning(char* str, char let);
extern "C" void _stdcall FindSubstr(char* str, int position, int length,
                                       char* substring);

int main() {
 char a[]="programming";
 //std::cout<< FindIndex(a, 'o');
 //std::cout << FindIndexFromBeginning(a, 'o');
 //std::cout<<CountLength(a);
 {
   char str[] = "aa cccc dd";

   int position = 3;
   const int lenght = 4;
   char substring[5] = "\0";
   FindSubstr(str, position, lenght, substring);
   std::cout << substring;  // cccc
 }

}