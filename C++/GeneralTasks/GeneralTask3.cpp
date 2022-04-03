#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
std::vector<std::string> FileReader(std::string input_file);
std::string ConsoleReader(std::string msg);
bool IsNonIncreasingOrder(std::string str);
std::vector<std::string> WordParser(std::vector<std::string> lines);
std::vector<std::string> FindItems(std::vector<std::string> lines);
int WordWeight(std::string);
void SortCollection(std::vector<std::string>);
void FileWriter(std::map<std::string, int> input_map);

int main()
{
	std::vector<std::string> Str;
	std::string input_file = ConsoleReader("Enter name of input file:");
	Str=FileReader(input_file);
	std::vector<std::string> GoodWords;
	GoodWords=FindItems(Str);
	for (size_t i = 0; i < GoodWords.size(); i++)
	{
		std::cout << GoodWords[i] << std::endl;
	}
	std::map<std::string, int> WordMap;
	for (int i = 0; i < GoodWords.size(); i++) 
	{
		WordMap.insert(std::make_pair(GoodWords[i], WordWeight(GoodWords[i])));
	}
	
	FileWriter(WordMap);
	system("pause");
	return 0;
}
std::vector<std::string> FindItems(std::vector<std::string> lines)
{
	std::vector<std::string> GoodWords;
	std::vector<std::string> Words = WordParser(lines);
	for (int i = 0; i < Words.size(); i++)
	{
		if (IsNonIncreasingOrder(Words[i]))
		{
			GoodWords.push_back(Words[i]);
		}
	}
	return GoodWords;
}
std::vector<std::string> WordParser(std::vector<std::string> lines)
{
	std::vector<std::string> Words;
	std::string str;
	for (int i = 0; i < lines.size(); ++i) {
		std::istringstream stream(lines[i]);
		while (!stream.eof())
		{
			stream >> str;
			Words.push_back(str);
		}
	}
	return Words;
}
std::string ConsoleReader(std::string msg)
{
	std::cout << msg << "\n";
	std::string str;
	std::cin >> str;
	return str;
}
std::vector<std::string> FileReader(std::string const input_file)
{
	std::vector<std::string> Str;
	std::ifstream in(input_file);
	if (!in)
	{
		std::cout << "Error file open\n";
	}
	std::string str;
	while (!in.eof())
	{
		getline(in, str);
		Str.push_back(str);
	}
	return Str;
}

bool IsNonIncreasingOrder(std::string str)
{
	bool flag = true;
	int n = str.size();
	for (int i = n - 1; i >1; i-=2) {
		if (str[i] < str[i - 2]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}
int WordWeight(std::string str)
{
	int weight = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int x = str[i];
		int y = str[i];
		x = y >> 2;
		x = y >> 4;
		if (x % 2 == 1 && y % 2 == 1)
		{
			weight += str[i];
		}
	}
	return weight;
}
void FileWriter(std::map<std::string, int> input_map) 
{
	std::ofstream out("output_file.txt");
	for (std::map< std::string, int >::iterator it = input_map.begin(); it != input_map.end(); it++)
	{
		out << it->first<<" " << it->second << "\n";
	}
}
void SortCollection(std::vector<std::string> words)
{
	std::sort(words.begin(), words.end(), [](std::string a, std::string b) {return (WordWeight(a) < WordWeight(b))?true:false; });
}
