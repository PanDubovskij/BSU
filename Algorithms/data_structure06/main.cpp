#include <iostream>
#include <vector>

class Tree {
    struct Node {
        long sum;
        int max;
        int min;
        int color;

        Node() {}
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

    void add(int a, int b, int x, int v, int tl, int tr, int leaveNum) {
        if (a == tl && tr == b) {
            s[v].sum += x * leaveNum;
            s[v].min += x;
            s[v].max += x;
            s[v].color += x;
            return;
        }

        if (tr < a || b < tl) { return; }
        if (2 * v + 1 < s.size()) {
            leaveNum >>= 1;
            int ind1 = v * 2 + 1;
            int ind2 = v * 2 + 2;
            if (s[v].color) { push(v, leaveNum); }
            int mid = (tl + tr) / 2;
            add(a, std::min(b, mid), x, ind1, tl, mid, leaveNum);
            add(std::max(a, mid + 1), b, x, ind2, mid + 1, tr, leaveNum);
            s[v].sum = s[ind1].sum + s[ind2].sum;
            s[v].min = std::min(s[ind1].min, s[ind2].min);
            s[v].max = std::max(s[ind1].max, s[ind2].max);
        }
    }

    long long sum(int a, int b, int v, int tl, int tr, int leaveNum) {
        if (a == tl && tr == b) { return s[v].sum; }

        if (tr < a || tl > b) { return 0; }

        leaveNum >>= 1;
        int mid = (tr + tl) / 2;
        if (s[v].color) { push(v, leaveNum); }
        return sum(std::max(a, mid + 1), b, v * 2 + 2, mid + 1, tr, leaveNum) +
               sum(a, std::min(b, mid), v * 2 + 1, tl, mid, leaveNum);
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

    int max(int a, int b, int v, int tl, int tr, int leaveNum) {
        if (a == tl && tr == b) { return s[v].max; }

        if (tr < a || tl > b) { return INT32_MIN; }

        leaveNum >>= 1;
        int mid = (tr + tl) / 2;
        if (s[v].color) { push(v, leaveNum); }
        return std::max(max(std::max(a, mid + 1), b, v * 2 + 2, mid + 1, tr, leaveNum),
                        max(a, std::min(b, mid), v * 2 + 1, tl, mid, leaveNum));
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 0;
    int pow2 = 1;
    std::cin >> n;
    while (pow2 < n) { pow2 <<= 1; }
    Tree tree(2 * pow2 - 1);
    int task = 0;
    while (std::cin >> task) {
        switch (task) {
            case 1: {
                int index = 0, x = 0;
                std::cin >> index >> x;
                tree.setValue(index, x, 0, 0, pow2 - 1, pow2);
                break;
            }
            case 2: {
                int a = 0, b = 0, x = 0;
                std::cin >> a >> b >> x;
                tree.add(a, b, x, 0, 0, pow2 - 1, pow2);
                break;
            }
            case 3: {
                int a = 0, b = 0;
                std::cin >> a >> b;
                std::cout << tree.sum(a, b, 0, 0, pow2 - 1, pow2) << "\n";
                break;
            }
            case 4: {
                int a = 0, b = 0;
                std::cin >> a >> b;
                std::cout << tree.min(a, b, 0, 0, pow2 - 1, pow2) << "\n";
                break;
            }
            case 5: {
                int a = 0, b = 0;
                std::cin >> a >> b;
                std::cout << tree.max(a, b, 0, 0, pow2 - 1, pow2) << "\n";
                break;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}