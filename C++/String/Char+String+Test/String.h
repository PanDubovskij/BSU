#pragma once
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
std::string DeleteWord(std::string str, std::string word) {
  int pos = 0;
  while (pos != std::string::npos) {
    pos = str.find(word);
    if (pos != std::string::npos) {
      str.erase(pos, word.length() + 1);
      pos += word.length();
    } else {
      break;
    }
  }
  return str;
}
std::string Reverse(std::string str) { 
 std::string str_new;
 str_new.assign(str.rbegin(), str.rend());
 return str_new;
}
std::ofstream WriteComments(std::string infile_name,std::string outfile_name) {
  std::ifstream in(infile_name);
  std::ofstream out(outfile_name);
  while (!in.eof()) {
    int pos = 0;
    std::string str;
    getline(in, str);
    pos = str.find('//');
    if (pos != std::string::npos) {
      out << str.assign(str.begin() + pos + 2, str.end()) << std::endl;
    }
  }
  return out;
}
std::string Strcat(std::string str, std::string add_str) {
  return str + add_str;
}
std::string RemoveExtraSpaces(std::string str) {
  int pos = 0;
  while (pos != std::string::npos) {
    pos = str.find("  ");
    if (pos != std::string::npos) {
      str.erase(pos, 1);
      pos++;
    }
  }
  return str;
}
std::string WriteThelongestWord(std::string str) {
  std::string longword, word;
  std::stringstream sstr;
  sstr << str;
  sstr >> longword;
  while (!sstr.eof()) {
    sstr >> word;
    if (word.length() > longword.length()) longword = word;
  }
  return longword;
}
std::string Replace(std::string str, std::string str1, std::string str2) {
  int pos = 0;
  while (pos != std::string::npos) {
    pos = str.find(str1);
    if (pos != std::string::npos) {
      str.replace(pos, str1.length(), str2);
    }
  }
  return str;
}