#include <iostream>
#include <vector>
#include <algorithm>
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

    bool unionSets(int x, int y) {
        bool flag = false;
        x = this->findSet(x);
        y = this->findSet(y);
        if (x != y) {
            if (this->size[x] < this->size[y]) {
                std::swap(x, y);
            }
            this->parent[y] = x;
            this->size[x] += this->size[y];
            flag = true;
        }
        return flag;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //n количество компонент связности
    int n, m, q;
    std::cin >> n >> m >> q;
    //город без дорог
    DisjointSetUnion dsu(n);
    int numberOfSets = n;

    //сохраняем ребра(дороги)
    int u, v;
    std::vector<std::pair<int, int>> roads;
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;
        --u;
        --v;
        roads.emplace_back(u, v);
    }
    //фиксируем какие дороги остались целы после землетрясений
    std::vector<bool> isDestroyed(m, false);
    std::vector<int> earthquakes;
    for (int i = 0; i < q; ++i) {
        int x=0;
        std::cin >> x;
        isDestroyed[x - 1] = true;
        earthquakes.push_back(x);
    }
    //добавляем дороги которые остались целы
    for (int i = 0; i < m; ++i) {
        if (!isDestroyed[i]) {
            if (dsu.unionSets(roads[i].first, roads[i].second)) {
                --numberOfSets;
            }
        }
    }

    if (numberOfSets == 1) {
        for (int i = 0; i < q; ++i) { std::cout << 1; }
        return 0;
    }


    //восстанавливаем дороги чтобы выяснить когда граф еще был связным
    int zeroCounter = 0;
    for (int i = q - 1; i >= 0; --i) {
        ++zeroCounter;
        int road=earthquakes[i];
        if (dsu.unionSets(roads[road-1].first, roads[road-1].second)) {
            --numberOfSets;
        }
        if (numberOfSets == 1) { break; }
    }
    for (int i = 0; i < q - zeroCounter; ++i) {
        std::cout<<1;
    }
    for (int i = 0; i < zeroCounter; ++i) {
        std::cout<<0;
    }
    return 0;
}
