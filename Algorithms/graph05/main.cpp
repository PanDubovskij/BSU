#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin>>n;
    std::vector<int> v(n);
    for (int k = 0; k < n - 1; ++k) {
        int i,j;
        std::cin>>i>>j;
        --j;
        v[j]=i;

    }
    for (int i = 0; i < n; ++i) {
        std::cout<<v[i]<<" ";
    }

    return 0;
}
