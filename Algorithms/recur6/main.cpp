#include <iostream>
#include <cmath>

long long subSequence(const long long *A, long long n) {
    auto *arr = new long long[n + 1];
    int length = 0;
    for (int i = 0; i < n; i++) {
        int start = 1;
        int end = length;
        while (start <= end)
        {
            int mid = std::ceil(((double) start + end) / 2);
            A[arr[mid]] < A[i] ? start = mid + 1 : end = mid - 1;
        }
        if (start > length) { length = start; }
        arr[start] = i;
    }
    return length;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n = 0;
    std::cin >> n;
    auto *A = new long long[n];
    for (int i = 0; i < n; i++) { std::cin >> A[i]; }
    std::cout << subSequence(A, n);
}