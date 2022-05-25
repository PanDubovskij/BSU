#include <iostream>

int multiplyOrder( int* p, int s ) {
		int n = s;

        int** arr = new int* [n];
        for (int i = 0; i < n; ++i)
        {
            arr[i] = new int[n]{};
        }

		for (int i = 0; i < n; ++i)
        {
			arr[i][i] = 0;
		}

		for (int l = 1; l < n; ++l)
        {
			for (int i = 0; i < n - l; ++i)
            {
				int j = i + l;
				arr[i][j] = INT32_MAX;
				for (int k = i; k < j; ++k) {
					arr[i][j] = std::min(arr[i][j], arr[i][k] + arr[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);
				}
			}
		}
		return arr[0][n - 1];
	}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen(R"(D:\programs\JetBrains\Toolbox\projects_clion\recur02\input.txt)", "r", stdin);
    freopen(R"(D:\programs\JetBrains\Toolbox\projects_clion\recur02\output.txt)", "w", stdout);
    int s = 0;
    std::cin >> s;
    int* arr = new int[s + 1];
    std::cin >> arr[0];
    for (int i = 1; i < s + 1; ++i)
    {
        std::cin >> arr[i];
        if (i < s)
        {
            int temp = 0;
            std::cin >> temp;
        }
    }
    std::cout << multiplyOrder(arr, s);
    return 0;
}
