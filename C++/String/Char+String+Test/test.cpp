#include "pch.h"
#include "C:\лабы\уп 2 сем\22.02.2021\22.02.2021\Char.h"

TEST(TestDeleteWord, CheckStr) {
  char str[] = "Hello world ";
  EXPECT_STREQ("Hello ", DeleteWord(str, "world"));
}
TEST(TestDeleteSpaces, CheckStr) {
  char str[] = "Hello          world";
  EXPECT_STREQ("Hello world", RemoveExtraSpaces(str));
}
TEST(TestDeleteSpaces, CheckStrWithout) {
  char str[] = "Hello world";
  EXPECT_STREQ("Hello world", RemoveExtraSpaces(str));
}
TEST(TestReplaceSubset, CheckStr) {
  char str[] = "Hello world";
  char str1[] = "Hello";
  char str2[] = "Goodbye";
  EXPECT_STREQ("Goodbye world", Replace(str, str1, str2));
}