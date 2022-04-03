#pragma once
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
char* Strcat(char* str1, const char* str2) {
  char* new_str = str1;
  while (*str1) str1++;
  while (*str2) {
    *str1 = *str2;
    str1++;
    str2++;
  }
  *str1 = '\0';
  return new_str;
}
char* RemoveExtraSpaces(char* s) {
  int len = strlen(s);
  for (int k = 0; k < len; k++) {
    for (int i = 0; i < len; i++) {
      if ((s[i] == ' ') && (s[i + 1] == ' ')) {
        for (int j = i; j < len - 1; j++) {
          s[j] = s[j + 1];
        }
        len--;
        s[len] = '\0';
      }
    }
  }
  return s;
}
void WriteThelongestWord(char* str) {
  int n = 0, maxn = 0, pos = 0, len;
  len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] != ' ') n++;
    if ((str[i] == ' ') || (len - i == 1)) {
      if (n > maxn) {
        pos = i - n;
        maxn = n;
      }
      n = 0;
    }
  }
  for (int i = 0; i < maxn; ++i) {
    std::cout<<str[i + pos];
  }
}
void Reverse(const char* str) {
  if (*str) {
    Reverse(str + 1);
    std::cout << *str;
  }
}
std::ofstream WriteComments(std::string infile_name, std::string outfile_name) {
  std::ifstream in(infile_name);
  std::ofstream out(outfile_name);
  while (!in.eof()) {
    std::string string;
    getline(in, string);
    int len = string.size();
    char* str=new char[len];
    for (int i = 0; i<string.size(); i++) {
      str[i]=string[i];
    }
    for (int i = 0; i < (len-1); i++) {
      if (str[i] == '/' && str[i + 1] == '/') {
        for (int j = i + 1; j < (len - 1); j++) {
          out << str[j + 1];
        }
        out << std::endl;
      }
    }
  }
  return out;
}
char* Replace(char* text, char* str1, char* str2) {
  char buf[1000];
  char* s = strstr(text, str1);
  while (s) {
    int len = strlen(text);
    int pos = len - strlen(s);
    strcpy(buf, s + strlen(str1));
    text[pos] = '\0';
    strcat(text, str2);
    strcat(text, buf);
    s = strstr(text, str1);
  }
  return text;
}
char* DeleteWord(char* str, const char* word) {
  int word_len = strlen(word);
  char* word_begin = strchr(str, int(word[0]));
  int new_len = strlen(word_begin);
  int amount = 0; 
  if (word_begin) {
    while (*word_begin != '\0' && *word_begin == *word) {
      ++word_begin;
      ++word;
      ++amount;
    }
    if (amount == word_len && *word_begin == ' ') {
      int start_elem = strlen(str) - new_len;
      for (int j = 0; j < amount; ++j) {
        str[start_elem] = ' ';
        start_elem++;
      }
    }
  }
  RemoveExtraSpaces(str);
  return str;
}