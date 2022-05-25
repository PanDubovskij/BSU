#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix;
std::vector<int> u;
int c = 0;

void check(int v, int n) {
    u[v] = 1;
    c++;
    for (int i = 0; i < n; i++)
        if (matrix[v][i] == 1 && u[i] == 0)
            check(i, n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;
    matrix = std::vector<std::vector<int>>(n, std::vector<int>(n));
    u = std::vector<int>(n);
    int e = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
            e += matrix[i][j];
        }
    }
    e /= 2;
    check(0, n);
    if (c == n && e == n - 1) { std::cout << "Yes"; }
    else { std::cout << "No"; }

    return 0;
}
