#include <iostream>
#include <vector>

int m, c, n;

int h(int i, int x) { return ((x % m) + c * i) % m; }

void setKey(std::vector<int> &arr) {
    int x = 0;
    int index;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        for (int j = 0; j < m; ++j) {
            index = h(j, x);
            if (arr[index] == x) { break; }
            if (arr[index] == -1) {
                arr[index] = x;
                break;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    m = 0, c = 0, n = 0;

    std::cin >> m >> c >> n;
    std::vector<int> arr(m,-1);

    setKey(arr);

    for (int i: arr) { std::cout << i << " "; }

    return 0;
}
