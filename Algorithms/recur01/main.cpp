#include <iostream>

long long ones(short N, short K)
{
    auto** arr = new long long* [N + 1];
    for (int i = 0; i < N + 1; ++i)
    {
        arr[i] = new long long[N + 1]{};
    }
    for (int i = 0; i <N+1; ++i) {
        arr[i][i] = 1;
    }
    for (int j = 0; j < N + 1; ++j) {
        arr[j][0] = 1;
    }
    for (int i = 1; i < N + 1; ++i)
    {
        for (int j = 1; j < N+1; ++j)
        {
            arr[i][j] = (arr[i - 1][j - 1] % (1000000000 + 7) + arr[i - 1][j] % (1000000000 + 7)) % (1000000000 + 7);
        }
    }

    long long amount = arr[N][K];

    for (int i = 0; i < N + 1; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return amount;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    short N=4,K=0;
    //std::cin>>N>>K;
    std::cout << ones(N, K);
    return 0;
}