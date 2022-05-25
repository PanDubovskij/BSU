#include <iostream>
#include <fstream>
#include <set>

int main()
{
    freopen("input.txt", "r", stdin);
    std::set<long long> Set;
    int vertex;
    while (std::cin>>vertex)
    {
        Set.insert(vertex);
    }
    long long sum = 0;
    for (long long x :Set) {
        sum += x;
    }
    std::ofstream out;
    out.open("output.txt");
    if (out.is_open())
    {
        out << sum << std::endl;
    }
    return 0;
}
