#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> A(n, std::vector<int>(n));
    for (int k = 0; k < m; ++k) {
        int i, j;
        std::cin >> i >> j;
        --i;
        --j;
        A[i][j] = 1;
        A[j][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
