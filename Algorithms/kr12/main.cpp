#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> A(n);
    bool flag = false;
    int i = 0;
   for(int j=0;j<n;j++) {
        int a;
        std::cin >> a;
        if (!a) { flag = true; }
        else {
            A[i] = std::abs(a);
            ++i;
        }
    }

    std::sort(A.begin(), A.end());
    int max_length_subseq = 0;
    std::vector<int> A_(i);
    for (int k = 0; k < i ;++k) {
        int max_length = 0;
        int j = 0;
        while (j < k) {
            if (!(A[k] % A[j]) ) {
                if (A_[j] > max_length) {
                    max_length = A_[j];
                }
            }
            j++;
        }
        A_[k] = max_length + 1;
        if (A_[k] > max_length_subseq) { max_length_subseq = A_[k]; }
    }
    if (flag) { max_length_subseq++; }
    std::cout << max_length_subseq;

    return 0;
}
