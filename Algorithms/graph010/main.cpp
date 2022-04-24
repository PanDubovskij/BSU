#include<iostream>
#include <vector>
#include<set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u - 1].push_back(std::make_pair(v - 1, w));
        graph[v - 1].push_back(std::make_pair(u - 1, w));
    }
    std::vector<long long> d(n, LLONG_MAX);
    d[0] = 0;
    std::set<std::pair<int, int> > q;
    q.insert(std::make_pair(d[0], 0));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (int j = 0; j < graph[v].size(); ++j) {
            int to = graph[v][j].first;
            int length = graph[v][j].second;
            if (d[v] + length < d[to]) {
                q.erase(std::make_pair(d[to], to));
                d[to] = d[v] + length;
                q.insert(std::make_pair(d[to], to));
            }
        }
    }
    std::cout << d[n - 1];
    return 0;
}