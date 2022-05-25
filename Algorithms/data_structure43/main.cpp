#include <iostream>
#include <vector>
#include <queue>

std::vector<long long>
huffmanCode(std::priority_queue<long long, std::vector<long long>, std::greater<>> &priorityQueue) {
    std::vector<long long> sums;
    while (priorityQueue.size() > 1) {
        long long one = priorityQueue.top();
        priorityQueue.pop();
        long long two = priorityQueue.top();
        priorityQueue.pop();
        priorityQueue.push(one + two);
        sums.push_back(one + two);
    }
    return sums;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);

    std::priority_queue<long long, std::vector<long long>, std::greater<>> priorityQueue;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long long elem = 0;
        std::cin >> elem;
        priorityQueue.push(elem);
    }

    long long textLength = 0;
    for (long long sum: huffmanCode(priorityQueue)) { textLength += sum; }
    std::cout << textLength;
    return 0;
}