#include<iostream>
#include<fstream>
#include<string>

int FindMax(int*, int);
void CountKeyWords(std::ifstream&, std::string[], int[], int);
void EraseKeyWord(std::ifstream&, std::ofstream&, std::string);
bool chekFileOpen(std::ifstream& in)
{
    if (!in.is_open())
    {
        std::cout << "Error file open\n";
        return false;
    }
    return true;
}
int main()
{
    {
        //task 1
        std::ifstream in("main.cpp");
        std::ofstream out("output1.txt");
        std::string str;
        if (chekFileOpen(in))
        {
            in.seekg(0, std::ios::beg);
            while (!in.eof())
            {
                getline(in, str);
                int position = 0;

                while (position != std::string::npos)
                {

                    position = str.find(std::string("char"));
                    if (position == std::string::npos)
                    {
                        break;
                    }
                    else
                    {
                        str.insert(position, std::string("unsigned "));
                        break;
                    }
                }
                out << str << "\n";
            }

        }
        in.close();
    }
    { //task 2
        std::ifstream in("Текст.txt");
        std::ofstream out("output2.txt");
        std::string str;
        std::string Pronaun("We");
        if (chekFileOpen(in))
        {
            in.seekg(0, std::ios::beg);
            while (!in.eof())
            {
                getline(in, str);
                int position = 0;
                while (position != std::string::npos)
                {
                    position = str.find(std::string("We"));

                    if (position == std::string::npos)
                    {
                        break;
                    }
                    else
                    {

                        str.replace(position, Pronaun.length(), std::string("They"));
                        position += 5;
                    }
                }
                int position1 = 0;
                while (position1 != std::string::npos)
                {
                    position1 = str.find(std::string("we"));

                    if (position1 == std::string::npos)
                    {
                        break;
                    }
                    else
                    {

                        str.replace(position1, Pronaun.length(), std::string("they"));
                        position1 += 5;
                    }
                }
                out << str << "\n";
            }

        }
        in.close();
    }
    {
        //task 3
        std::ifstream in("main.cpp");
        std::ofstream out("output3.txt");

        const size_t size = 7;
        std::string keyWords[size] = { "if", "while", "int", "return", "true", "false", "bool" };
        int countWords[size] = {};

        CountKeyWords(in, keyWords, countWords, size);

        for (int i = 0; i < size; ++i)
        {
            out << keyWords[i] << " " << countWords[i] << std::endl;
        }

        int index = FindMax(countWords, size);
        EraseKeyWord(in, out, keyWords[index]);
    }
    {
        //task 4
        std::ifstream in("input4.txt");
        std::ofstream out("output4.txt");

        if (chekFileOpen(in))
        {
            double value;
            in >> value;
            int rub = (int)value;
            int kop = (int)round((value - rub) * 100);

            std::string output = std::to_string(rub);
            for (int i = output.length() - 3; i > 0; i -= 3)
            {
                output.insert(i, " ");
            }

            int remainder = rub % 100;
            if (remainder / 10 == 1)
            {
                remainder = 0;
            }
            remainder %= 10;
            switch (remainder)
            {
            case 1:
                output += " рубль";
                break;
            case 2:
            case 3:
            case 4:
                output += " рубля";
                break;
            default:
                output += " рублей";
                break;
            }
            output += " " + std::to_string(kop) + " коп.";

            out << output << std::endl;
        }
    }
    
    system("pause");
    return 0;
}
int FindMax(int* a, int size)
{
    int iMax = 0;
    for (int i = 1; i < size; ++i)
    {
        if (a[i] > a[iMax])
        {
            iMax = i;
        }
    }
    return iMax;
}
void CountKeyWords(std::ifstream& fin, std::string keyWords[], int countWords[], int size)
{
    if (chekFileOpen(fin))
    {
        std::string str;
        while (!fin.eof())
        {
            getline(fin, str);
            for (int i = 0; i < size; ++i)
            {
                int position = 0;
                while (position != std::string::npos)
                {
                    position = str.find(keyWords[i], position);
                    if (position == std::string::npos)
                    {
                        break;
                    }
                    else
                    {
                        position++;
                        countWords[i]++;
                    }
                }
            }
        }
    }
}

void EraseKeyWord(std::ifstream& fin, std::ofstream& fout, std::string keyWord)
{
    fin.seekg(0, std::ios::beg); // Переместились в начало файла
    std::string str;
    while (!fin.eof())
    {
        getline(fin, str);
        int position = 0;
        while (position != std::string::npos)
        {
            position = str.find(keyWord, position);
            if (position == std::string::npos)
            {
                break;
            }
            else
            {
                str.erase(position, keyWord.length());
                position++;
            }
        }
        fout << str << std::endl;
    }
}