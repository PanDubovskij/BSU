#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n, std::vector<int>());
    for (int k = 0; k < m; ++k) {
        int i, j;
        std::cin >> i >> j;
        v[i - 1].push_back(j);
        v[j - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << v[i].size() << " ";
        for (int j: v[i]) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
