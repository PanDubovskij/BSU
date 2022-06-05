#include <iostream>
#include <sstream>
#include <cmath>

int main() {
    int x;
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    while (ss >> x) {
        std::cout << pow(x, 3) << " ";
    }
    std::cout << '\n';
    //std::cout << "\n------------PROCESS P FINISHED---------------\n";
    return 0;
}