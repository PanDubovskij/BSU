#include <iostream>
#include <cmath>

std::string getMaxStringPalindrom(std::string str) {
    int n = str.length();
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {arr[i][i] = 1;}

    for (int i = 0; i < n - 1; ++i) {
        (str[i] != str[i + 1])?
                                (arr[i][i + 1] = 1):
                                (arr[i][i + 1] = 2);
    }
    for (int stolbec = 2; stolbec < n; stolbec++) {
        for (int i = 0, j = i + stolbec; j < n; i++, j++) {
            (str[i] == str[j])?
                                (arr[i][j] = (arr[i + 1][j - 1] + 2)):
                                (arr[i][j] = std::max(arr[i + 1][j], arr[i][j - 1]));
        }
    }
    int length = arr[0][n - 1];

    std::string palindrom;
    for (int i = 0; i < length; i++) {
        palindrom.append(" ");
    }
    int curr_row = 0;
    int curr_column = n - 1;
    int start = 0;
    int end = length - 1;
    while (length >= length / 2) {
        if (str[curr_row] == str[curr_column]) {
            palindrom[start] = str[curr_row];
            palindrom[end] = str[curr_row];
            start++;
            end--;
            curr_row++;
            curr_column--;
            length -= 2;
        }
        else if (arr[curr_row][curr_column] == arr[curr_row + 1][curr_column]) {
            curr_row++;
        }
        else {
            curr_column--;
        }
    }
    return palindrom;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::string string;
    std::cin >> string;
    std::string palindrom = getMaxStringPalindrom(string);
    std::cout << palindrom.length() << "\n" << palindrom;

}