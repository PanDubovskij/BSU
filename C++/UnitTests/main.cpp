#include "Header.h"


int main()
{
	std::ifstream in("input.txt");
	std::vector<std::string> Strings;
	if(CheckFileIsOpen(in))
	{	
		std::string word;
		std::cout << "Enter word, which should be deleted\n";
		std::cin >> word;
		std::ofstream out("output.txt");
		std::string str;
		while (!in.eof())
		{
			getline(in, str);
			str=DeleteWord(str, word);
			Strings.push_back(str);
		}
		sort(Strings.begin(), Strings.end());
		PrintInFile(Strings, out);
	}
	in.close();
	system("pause");
	return 0;
}