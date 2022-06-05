#include <iostream>
#include <sstream>

int main() {
    int x;
    int N = 5;
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    while (ss >> x) {
        std::cout << x + N << " ";
    }
    std::cout << '\n';
    //std::cout << "\n------------PROCESS A FINISHED---------------\n";
    return 0;
}