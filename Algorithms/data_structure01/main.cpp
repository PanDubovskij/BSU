#include <iostream>
#include <vector>

bool binarySearch(const std::vector<long long> &arr, long long x) {
    int l = 0;
    int size = arr.size();
    while (l < size) {
        int k = (l + size) / 2;
        if (x == arr[k]) { return true; }
        else if (x < arr[k]) { size = k; }
        else { l = k + 1; }
    }
    return false;
}

int lowerBound(const std::vector<long long> &arr, long long x) {
    int l = 0;
    int size = arr.size();
    while (l < size) {
        int k = (l + size) / 2;
        if (x <= arr[k]) { size = k; }
        else { l = k + 1; }
    }
    return l;
}

int upperBound(const std::vector<long long> &arr, long long x) {
    int l = 0;
    int size = arr.size();
    while (l < size) {
        int k = (l + size) / 2;
        if (x < arr[k]) { size = k; }
        else { l = k + 1; }
    }
    return l;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<long long> arr;
    int n = 0;
    std::cin >> n;
    while (n) {
        long long temp = 0;
        std::cin >> temp;
        arr.push_back(temp);
        --n;
    }
    int k = 0;
    std::cin >> k;
    while (k) {
        long long x;
        std::cin >> x;
        std::cout << binarySearch(arr, x) <<" "<< lowerBound(arr, x) <<" "<< upperBound(arr, x) << '\n';
        --k;
    }

    return 0;
}
