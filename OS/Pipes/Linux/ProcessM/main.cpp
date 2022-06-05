#include <iostream>
#include <sstream>

int main() {
    int x;
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    while (ss >> x) {
        std::cout << x * 7 << " ";
    }
    //std::cout << "\n------------PROCESS M FINISHED---------------\n";
    std::cout << '\n';
    return 0;
}