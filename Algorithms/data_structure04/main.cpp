#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n = 0, count = 0;
    std::cin >> n;
    while (n) {
        if (n % 2 == 1) {
            std::cout << count << std::endl;
        }
        n /= 2;
        count++;
    }

    return 0;
}
