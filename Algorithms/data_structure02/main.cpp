#include <iostream>
#include <vector>
#include <valarray>

void Add(std::vector<long long > &sq, std::vector<long long> &subSum, long long k, long long i, long long x) {
    sq[i] += x;
    subSum[i / k] += x;
}

long long FindSum(const std::vector<long long> &sq, std::vector<long long> &subSum, long long k, long long l, long long r) {
    long long sum = 0;
    long long jl = l / k;
    long long jr = r / k;
    if (jl == jr) {
        for (long long i = l; i < r; ++i) {
            sum += sq[i];
        }
        return sum;
    } else {
        for (long long i = l; i < (jl + 1) * k; ++i) {
            sum += sq[i];
        }
        for (long long i = jl + 1; i < jr; ++i) {
            sum += subSum[i];
        }
        for (long long i = jr * k; i < r; ++i) {
            sum += sq[i];
        }
        return sum;
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<long long> sq;
    long long n = 0;
    std::cin >> n;
    long long n_ = n;
    while (n_) {
        long long a = 0;
        std::cin >> a;
        sq.push_back(a);
        --n_;
    }

    long long k = (long long ) sqrt(n);
    std::vector<long long> subSum;
    for (long long i = 0; i < n; i += k) {
        long long sum = 0;
        for (long long j = i; j < i + k; ++j) {
            sum += sq[j];
        }
        subSum.push_back(sum);
    }

    long long q = 0;
    std::cin >> q;
    while (q) {
        std::string request;
        std::cin >> request;
        if (request == "FindSum") {
            long long l = 0;
            long long r = 0;
            std::cin >> l >> r;
            std::cout << FindSum(sq, subSum, k, l, r) << "\n";
        } else if (request == "Add") {
            long long i = 0;
            long long x = 0;
            std::cin >> i >> x;
            Add(sq, subSum, k, i, x);
        }
        --q;
    }

    return 0;
}
