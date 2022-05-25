#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>k;
            if (k==1) { a[j] = i + 1; }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    return 0;
}
