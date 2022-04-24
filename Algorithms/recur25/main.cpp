#include <iostream>

void strTransformation() {
    int x, y, z;
    std::string A;
    std::string B;
    std::cin >> x >> y >> z >> A >> B;
    int n = A.size();
    int m = B.size();
    int **arr = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        arr[i] = new int[m + 1]{};
    }

    for (int i = 0; i < n + 1; ++i) {
        arr[i][0] = i * x;
    }
    for (int j = 0; j < m + 1; ++j) {
        arr[0][j] = j * y;
    }
    for (int i = 1; i < n + 1; ++i) {
        int delta = 1;
        for (int j = 1; j < m + 1; ++j) {
            if (A[i - 1] == B[j - 1]) { delta = 0; }
            else {delta=1;}
            arr[i][j] = std::min(std::min(arr[i - 1][j] + x, arr[i][j - 1] + y), arr[i - 1][j - 1] + delta * z);
        }
    }
    std::cout << arr[n][m];
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("D:\\programs\\JetBrains\\Toolbox\\projects_clion\\recur25\\in.txt", "r", stdin);
    freopen("D:\\programs\\JetBrains\\Toolbox\\projects_clion\\recur25\\out.txt", "w", stdout);
    strTransformation();

    return 0;
}