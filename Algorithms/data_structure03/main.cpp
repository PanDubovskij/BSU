#include <iostream>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n = 0;
    std::cin >> n;
    if (n == 1) {
        std::cout << "YES\n";
        return 0;
    }
    std::vector<long long> binaryHeap(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> binaryHeap[i];
    }
    if (n == 2 && (binaryHeap[0] <= binaryHeap[1])) { std::cout << "YES\n"; }
    else {
        bool flag = true;
        long long i = 0;
        for (; i < (n - 1) / 2; ++i) {
            if (binaryHeap[i] > binaryHeap[2 * i + 1] ||
                binaryHeap[i] > binaryHeap[2 * i + 2]) {
                flag = false;
                break;
            }
        }
        if (i == (n - 1) / 2 && binaryHeap[i] > binaryHeap[2 * i + 1]) { flag = false; }

        if (flag) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
