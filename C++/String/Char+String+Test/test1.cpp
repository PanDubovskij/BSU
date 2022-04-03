#include "pch.h"
#include "C:\лабы\уп 2 сем\22.02.2021\22.02.2021\String.h"

TEST(TestDeleteWord, CheckStr) {
  std::string str = "Hello world ";
  EXPECT_EQ("Hello ", DeleteWord(str, "world"));
}
TEST(TestDeleteWord, CheckStrWithout) {
  std::string str = "Hello world ";
  EXPECT_EQ("Hello world ", DeleteWord(str, "goodbye"));
}
TEST(TestDeleteSpaces, CheckStr) {
  std::string str = "Hello          world";
  EXPECT_EQ("Hello world", RemoveExtraSpaces(str));
}
TEST(TestDeleteSpaces, CheckStrWithout) {
  std::string str = "Hello world";
  EXPECT_EQ("Hello world", RemoveExtraSpaces(str));
}
TEST(TestStrcat, CheckStr) {
  std::string str = "Hello ";
  str = Strcat(str, "world");
  EXPECT_EQ(str, "Hello world");
}

TEST(TestLongestWord, CheckStr) {
  std::string str = "I love programming";
  EXPECT_EQ("programming", WriteThelongestWord(str));
}
TEST(TestReverseStr, CheckStr) {
  std::string str = "Hello world";
  EXPECT_EQ("dlrow olleH", Reverse(str));
}
TEST(TestReplaceSubset, CheckStr) {
  std::string str = "Hello world";
  std::string str1 = "Hello";
  std::string str2 = "Goodbye";
  EXPECT_EQ("Goodbye world", Replace(str,str1,str2));
}