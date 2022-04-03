#include "pch.h"
#include "C:\лабы\задание 8\задание 8\Header.h"

TEST(TestCheckFile, CheckInOpen) {
	std::ifstream in;
	in.open("input.txt");
	ASSERT_EQ(in.is_open(), CheckFileIsOpen(in));
}

TEST(TestDeleteWord, CheckStr)
{
	std::string str = "Hello world ";
	EXPECT_EQ("Hello ", DeleteWord(str, "world"));
}

TEST(TestDeleteWord, CheckStrWithOut)
{
	std::string str = "Hello world ";
	EXPECT_EQ("Hello world ", DeleteWord(str, "goodbye"));
}
TEST(TestCheckFile, PrintInFile) {
	std::ofstream outf;
	outf.open("output.txt");
	ASSERT_EQ(1, outf.is_open());
}