#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include<sstream>
#include <cctype>
#include<cstdlib>
#include <cstring>
//#include "String.h"
#include "Char.h"

int main() {
   //std::string str = "I        love       programming";
   //str = RemoveExtraSpaces(str);
   //std::cout << DeleteWord(str,"love")<<std::endl;
   //std::cout << Reverse(str)<<std::endl;
   //WriteComments("input.txt", "output.txt");
   //str = Strcat(str, " very");
   //str = Strcat(str, " much");
   //std::cout << str;
   //std::cout << std::endl;
   //std::cout << WriteThelongestWord(str);
   //std::string str1 = "love";
   //std::string str2 = "hate";
   //std::cout << std::endl;
   //std::cout << Replace(str,str1,str2);
  char str[] = "Hello world ";
   std::cout << DeleteWord(str, "goodbye");
 /*  char s[]="I          love            programming";
   const char* word= "love";*/
 /*  str_erase(string, word);
   std::cout << string;
   std::cout<<myStrcat(string, " very much ");*/
   //char* str1 = new char[]{"i love programming"};
   //char* str2 = new char[]{" very much"};
   //std::cout << Strcat(str1, str2);
   //std::cout<<RemoveExtraSpaces(s)<<std::endl;
  //char text[] = "I love programming";
  //std::cout << DeleteWord(text, "love");/*
 /* char str1[] = "love";
  char str2[] = "hate";
  std::cout << "String after replacing\n" << Replace(text,str1,str2) <<std::endl;*/
  //char str[] = "Hello world ";
  //std::cout<<DeleteWord(str, "world");
}