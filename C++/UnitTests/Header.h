#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

std::string DeleteWord(std::string str, std::string word)
{
	int pos = 0;
	while (pos != std::string::npos)
	{
		pos = str.find(word);
		if (pos != std::string::npos)
		{
			str.erase(pos, word.length() + 1);
			pos += word.length();
		}
		else
		{
			break;
		}

	}
	return str;
}
void PrintInFile(std::vector<std::string> Strings, std::ofstream& out)
{
	for (int i = 0; i < Strings.size(); i++)
	{
		out << Strings[i] << "\n";
	}
}
bool CheckFileIsOpen(std::ifstream& in)
{
	if (!in.is_open())
	{
		std::cout << "File isn't open\n";
		return false;
	}
	else
	{
		return true;
	}
}
