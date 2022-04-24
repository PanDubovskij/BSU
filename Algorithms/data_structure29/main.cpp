#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

constexpr int MAX_TIME(2520);

struct habitant {
    int island;
    int time;

    habitant(int island_ = -1, int time_ = 0) : island(island_), time(time_) {};
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> c(n);
    int CURRENT_MAX_TIME = 1;
    std::vector<int> visits(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
        c[i] = a[i] + b[i];
        if (CURRENT_MAX_TIME < MAX_TIME) { CURRENT_MAX_TIME = std::lcm(CURRENT_MAX_TIME, c[i]); }
    }
    int time;
    bool isPossible = false;
    std::queue<habitant> q;
    int current_time = 0;
    q.push(habitant());
    while (!q.empty() && !isPossible) {
        habitant current = q.front();
        q.pop();
        if (current_time < current.time + 1) {
            ++current_time;
            for (int i = 0; i < n; i++) { visits[i] = false; }
        }
        for (int i = current.island - 5; i <= (current.island + 5); i++) {
            if ((i > -1) && (i < n) && !visits[i] && (current.time + 1 < CURRENT_MAX_TIME) &&
                ((current.time % c[i]) < a[i])) {
                q.push(habitant(i, current.time + 1));
                visits[i] = true;
            } else if ((i == -1) && ((current.time + 1) < CURRENT_MAX_TIME)) { q.push(habitant(-1, current.time + 1)); }
            else if ((i == n) && ((current.time + 1) <= CURRENT_MAX_TIME + 1)) {
                time = current.time + 1;
                isPossible = true;
            }
        }
    }

    if (isPossible) { std::cout << time; }
    else { std::cout << "No"; }

    return 0;
}