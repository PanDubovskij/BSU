#include <iostream>
#include <vector>
//#include <boost>

struct DisjointSetUnion {
    std::vector<int> parent;
    std::vector<int> size;

    DisjointSetUnion(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    };

    int findSet(int x) {
        if (x == this->parent[x]) { return x; }
        this->parent[x] = this->findSet(this->parent[x]);
        return this->parent[x];
    }

    int unionSets(int x, int y, int& n) {
        x = this->findSet(x);
        y = this->findSet(y);
        if (x != y) {
            if (this->size[x] < this->size[y]) {
                std::swap(x, y);
            }
            this->parent[y] = x;
            this->size[x] += this->size[y];
            --n;
        }
        return n;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q;
    std::cin >> n >> q;
    DisjointSetUnion dsu(n);

    int u, v;
    while (q) {
        std::cin >> u >> v;
        --u;
        --v;
        std::cout << dsu.unionSets(u, v, n) << "\n";
        --q;
    }

    return 0;
}
