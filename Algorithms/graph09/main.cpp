#include <iostream>
#include <vector>

int n, num;
std::vector<std::vector<int>> g;
std::vector<int> key;
std::vector<bool> visit;

void dfs(int v) {
    visit[v] = true;
    ++num;
    key[v] = num;
    for (int i = 0; i < n; ++i) {
        if (g[v][i] == 1 && !visit[i]) { dfs(i); }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin >> n;
    g = std::vector<std::vector<int>>(n, std::vector<int>(n));
    key = std::vector<int>(n);
    visit = std::vector<bool>(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; ++i) { if (!visit[i]) { dfs(i); }}

    for (int i = 0; i < n; ++i) { std::cout << key[i] << " "; }

    return 0;
}
