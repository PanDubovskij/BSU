#include <iostream>
#include <list>
#include <vector>

std::vector<std::vector<int>> g;
std::vector<bool> metOdd;
std::vector<bool> metEven;
std::vector<int> minOdd;
std::vector<int> minEven;

struct Pair {
    int number;
    bool flag;

    Pair(int n, bool f) : number(n), flag(f) {}
};

void bfs() {
    std::list<Pair> l;
    Pair p(1, true);
    l.push_back(p);
    while (!l.empty()) {
        Pair u = l.front();
        l.pop_front();
        for (int v: g[u.number]) {
            if (u.flag) {
                if (!metOdd[v]) {
                    metOdd[v] = true;
                    minOdd[v] = minEven[u.number] + 1;
                    Pair pair(v, false);
                    l.push_back(pair);
                }
            } else {
                if (!metEven[v]) {
                    metEven[v] = true;
                    minEven[v] = minOdd[u.number] + 1;
                    Pair pair(v, true);
                    l.push_back(pair);
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> mt(n + 1, -1);
    g = std::vector<std::vector<int>>(n + 1);
    int x, y;
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    metEven = std::vector(n + 1, false);
    metOdd = std::vector(n + 1, false);
    minOdd = std::vector(n + 1, INT32_MAX);
    minEven = std::vector(n + 1, INT32_MAX);
    metEven[1] = true;
    minEven[1] = false;
    bfs();
    int col;
    std::cin >> col;
    int to, steps;
    for (int j = 0; j < col; j++) {
        std::cin >> to >> steps;
        if (to == 1 && g[1].empty()) {
            if (steps > 0) {
                std::cout << "No\n";
            } else {
                std::cout << "Yes\n";
            }
        } else {
            if (steps % 2 == 0) {
                if (minEven[to] <= steps) {
                    std::cout << "Yes\n";
                } else {
                    std::cout << "No\n";
                }
            } else {
                if (minOdd[to] <= steps) {
                    std::cout << "Yes\n";
                } else {
                    std::cout << "No\n";
                }
            }
        }
    }

    return 0;
}
