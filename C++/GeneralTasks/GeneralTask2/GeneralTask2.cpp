#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include<cmath>
#include<algorithm>

void ReadInput(std::string const FILE_NAME, std::vector<std::string>& V, int& k);
std::vector<std::pair<std::string, size_t>> AnnotateWithPositions(std::vector<std::string>& V);
std::ostream& operator <<(std::ostream& out, const std::pair<std::string, size_t>& p);
void RemoveByLengthDiff(std::vector<std::string>& W, int k);
void Sort(std::vector<std::pair<std::string, size_t>>& Pairs);
void WriteCollection(std::string const FILE_NAME, std::vector<std::pair<std::string, size_t>> Pairs);
int EraseMaxNumber(int a);
int main()
{
	{
		std::vector<std::string> V;
		std::vector<std::pair<std::string, size_t>> Pairs;
		int k;
		ReadInput("Text.txt", V, k);
		//RemoveByLengthDiff(V, k);
		Pairs = AnnotateWithPositions(V);
		Sort(Pairs);
		WriteCollection("output.txt", Pairs);
	}
	{
		std::vector<int> Numbers;
		std::cout << "Enter a and b\n";
		int a, b;
		std::cin >> a >> b;
		for (; a <= b; a++)
		{
			Numbers.push_back(EraseMaxNumber(a));
		}
		for (size_t i = 0; i < Numbers.size(); i++)
		{
			std::cout << Numbers[i] << "  ";
		}
	}
	system("pause");
	return 0;
}

int EraseMaxNumber(int a)
{
	int n = log10(a) + 1;
	int max = 0;
	int n_max = 0;
	int b = a;
	for (int i = 1; i <= n; ++i) {
		if (b % 10 > max) {
			max = b % 10;
			n_max = i;
		}
		b /= 10;
	}

	int t;
	t = pow(10, n_max);
	b = a / t;
	b = b * t / 10 + a % (t / 10);
	return b;
}
void ReadInput(std::string const FILE_NAME, std::vector<std::string>& V, int& k)
{
	std::ifstream in(FILE_NAME);
	if (!in)
	{
		std::cout << "Error file open\n";
		return;
	}
	size_t size;
	in >> size;
	std::string str;
	for (size_t i = 0; i < size; i++)
	{
		in >> str;
		V.push_back(str);
	}
	in >> k;
}
std::vector<std::pair<std::string, size_t>> AnnotateWithPositions(std::vector<std::string>& V)
{
	std::vector<std::pair<std::string, size_t>> Pairs;
	for (size_t i = 0; i < V.size(); i++)
	{
		Pairs.push_back(std::make_pair(V[i], i + 1));
	}
	return Pairs;
}
std::ostream& operator <<(std::ostream& out, const std::pair<std::string, size_t>& p)
{
	out << p.first << " " << p.second;
	return out;
}
void RemoveByLengthDiff(std::vector<std::string>& W, int k)
{
	for (int i = W.size() - 1; i > 0; i--)
		if (fabs((int)W[i].size() - (int)W[i - 1].size()) == k)
			W.erase(W.begin() + i);
}
void Sort(std::vector<std::pair<std::string, size_t>>& Pairs)
{
	std::sort(Pairs.begin(), Pairs.end(),
		[

		]
	(
		std::pair<std::string, size_t> Pair1, std::pair<std::string, size_t> Pair2
		)
		{
			if (Pair1.first == Pair2.first)
				return (Pair1.second > Pair2.second);
			else
				return (Pair1.first < Pair2.first);
		});
}
void WriteCollection(std::string const FILE_NAME, std::vector<std::pair<std::string, size_t>> Pairs)
{
	std::ofstream out(FILE_NAME);
	for (size_t i = 0; i < Pairs.size(); i++)
	{
		out << Pairs[i] << "\n";
	}
}
