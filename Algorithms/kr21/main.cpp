#include <iostream>
#include <vector>

class Tree {
    struct Node {
        long sum;
        int max;
        int min;
        int color;

        Node() = default;
    };

    std::vector<Node> s;

public:
    Tree(int n) { s = std::vector<Node>(2 * n, Node()); }

    void push(int v, int leaveNum) {
        if (s[v].color && (v * 2 + 1 < s.size())) {
            int ind1 = v * 2 + 1;
            int ind2 = v * 2 + 2;
            s[ind1].sum += leaveNum * s[v].color;
            s[ind2].sum += leaveNum * s[v].color;

            s[ind1].min += s[v].color;
            s[ind1].max += s[v].color;

            s[ind2].min += s[v].color;
            s[ind2].max += s[v].color;

            s[ind1].color += s[v].color;
            s[ind2].color += s[v].color;
            s[v].color = 0;
        }
    }

    void setValue(int i, int x, int v, int tl, int tr, int leaveNum) {
        if (i == tl && i == tr) {
            s[v].min = x;
            s[v].max = x;
            s[v].sum = x;
            return;
        }

        if (tr < i || i < tl) { return; }

        int mid = (tl + tr) / 2;
        leaveNum >>= 1;
        int ind1 = v * 2 + 1;
        int ind2 = v * 2 + 2;
        if (s[v].color) { push(v, leaveNum); }
        if (i <= mid) { setValue(i, x, ind1, tl, mid, leaveNum); }
        else { setValue(i, x, ind2, mid + 1, tr, leaveNum); }
        s[v].sum = s[ind1].sum + s[ind2].sum;
        s[v].min = std::min(s[ind1].min, s[ind2].min);
        s[v].max = std::max(s[ind1].max, s[ind2].max);
    }

    int max(int a, int b, int v, int tl, int tr, int leaveNum) {
        if (a == tl && tr == b) { return s[v].max; }

        if (tr < a || tl > b) { return INT32_MIN; }

        leaveNum >>= 1;
        int mid = (tr + tl) / 2;
        if (s[v].color) { push(v, leaveNum); }
        return std::max(max(std::max(a, mid + 1), b, v * 2 + 2, mid + 1, tr, leaveNum),
                        max(a, std::min(b, mid), v * 2 + 1, tl, mid, leaveNum));
    }

    int min(int a, int b, int v, int tl, int tr, int leaveNum) {
        if (a == tl && tr == b) { return s[v].min; }

        if (tr < a || tl > b) { return INT32_MAX; }

        int mid = (tr + tl) / 2;
        leaveNum >>= 1;
        if (s[v].color) { push(v, leaveNum); }
        return std::min(min(std::max(a, mid + 1), b, v * 2 + 2, mid + 1, tr, leaveNum),
                        min(a, std::min(b, mid), v * 2 + 1, tl, mid, leaveNum));
    }

    long long maxMult(int x, int y, int v, int tl, int tr, int leaveNum) {

        std::vector<int> temp;

        long long mm=0;

        return mm;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 0;
    int q = 0;
    int pow2 = 1;
    std::cin >> n;
    std::cin >> q;


    while (pow2 < n) { pow2 <<= 1; }
    Tree tree(2 * pow2 - 1);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        tree.setValue(i, a, 0, 0, pow2 - 1, pow2);
    }
    char task;
    while (std::cin >> task) {
        switch (task) {
            case '=': {
                int x = 0, y = 0;
                std::cin >> x >> y;
                tree.setValue(x, y, 0, 0, pow2 - 1, pow2);
                break;
            }
            case '?': {
                int x = 0, y = 0;
                std::cin >> x >> y;
                std::cout << tree.maxMult(x, y, 0, 0, pow2 - 1, pow2) << "\n";
                break;
            }
            default: {
                break;
            }
        }
    }

    return 0;
}