#include <bits/stdc++.h>

std::vector<unsigned long long> sequence;
unsigned long long power;
unsigned long long dp[19][182][110][2]; // pos - sum - remainder - flag
unsigned long long p, q, k;
unsigned long long a, b;

unsigned long long
calcRes(unsigned long long pos, unsigned long long sum, unsigned long long num, unsigned long long flag) {
    if (pos == power) {
        if (sum >= p && sum <= q && num % k == 0) { return 1; }

        return 0;
    }

    if (dp[pos][sum][num % k][flag] != -1) { return dp[pos][sum][num % k][flag]; }

    unsigned long long maxdigit = 9;

    if (flag) { maxdigit = sequence[pos]; }

    unsigned long long res = 0;
    for (unsigned long long i = 0; i <= maxdigit; i++) {
        bool nextFlag = (i == maxdigit && flag);
        res += calcRes(pos + 1, sum + i, (num * 10 + i) % k, nextFlag);
    }

    return dp[pos][sum][num % k][flag] = res;
}

unsigned long long solve(unsigned long long n) {

    sequence.clear();
    while (n) {
        sequence.push_back(n % 10);
        n /= 10;
    }
    reverse(sequence.begin(), sequence.end());
    power = sequence.size();

    memset(dp, -1, sizeof(dp));

    return calcRes(0, 0, 0, 1);
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin >> k >> a >> b >> p >> q;

    //тест
    // 93
    // 717362973 897289192
    // 1 7

    std::cout << solve(b) - solve(a - 1);

    return 0;
}