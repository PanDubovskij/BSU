#include <iostream>

long long modexp(long long x, long long y, long long N)
{
    if (!y) return 1;
    if (y % 2 == 0) {
        long long z = modexp(x, y / 2, N);
        return (z * z) % N;
    }
    else { return (x *modexp(x,y-1,N)) % N; }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N,K;
    std::cin >> N >> K;
    int p = 1000000007;
    long long chisl = 1,znamen=1;
    for (int i = N; i > N - K; i--) {
        chisl = (chisl * i) % p;
    }
    for (int i = 1; i < K+1; i++) {
        znamen = (znamen * i) % p;
    }
    std::cout << (chisl* modexp(znamen,p-2,p))%p;
}