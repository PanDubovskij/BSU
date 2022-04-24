#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin>>n;
    std::vector<std::vector<int>> g(n, std::vector<int>(n));
    std::vector<int> key(n);
    std::vector<bool> visit(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>g[i][j];
        }
    }
    std::queue<int> q;
    int num=0;
    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            ++num;
            key[i]=num;
            visit[i]=true;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int j = 0; j < n; ++j) {
                    if (g[v][j]==1 && !visit[j]) {
                        ++num;
                        key[j]=num;
                        visit[j]= true;
                        q.push(j);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout<<key[i]<<" ";
    }
    return 0;
}
