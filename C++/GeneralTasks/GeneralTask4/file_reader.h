#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include <iostream>
class FileReader {
public:
	std::vector<std::string> ReadLines(const std::string& file_path)
	{
		std::vector<std::string> lines;
		std::ifstream in(file_path);
		if (!in.is_open())
		{
			std::cout << "Error file open\n";
		}
		std::string str;
		while (!in.eof())
		{
			getline(in, str);
			lines.push_back(str);
		}
		return lines;
	}
	std::vector<std::string> ReadWords(const std::string& file_path)
	{
		std::vector<std::string> lines;
		std::ifstream in(file_path);
		if (!in.is_open())
		{
			std::cout << "Error file open\n";
		}
		std::string str;
		while (!in.eof())
		{
			getline(in, str);
			lines.push_back(str);
		}
		std::vector<std::string> Words;
		std::string Str;
		for (int i = 0; i < lines.size(); ++i) {
			std::istringstream stream(lines[i]);
			while (!stream.eof())
			{
				stream >> Str;
				Words.push_back(Str);
			}
		}
		return Words;
	}
};

