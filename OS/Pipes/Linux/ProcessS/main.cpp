#include <iostream>
#include <sstream>

int main() {
    int x;
    int sum = 0;
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    while (ss >> x) {
        sum += x;
    }
    std::cout << sum << '\n';
    //std::cout << sum << "\n------------PROCESS S FINISHED---------------\n";
    return 0;
}