#include <iostream>
#include <set>
#include <vector>
#include <map>

struct compar {
    bool operator()(const std::pair<std::string, long long> &a, const std::pair<std::string, long long> &b) const {
        return (a.second < b.second);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int L, R, q;
    std::cin >> L >> R >> q;
    std::set<std::pair<std::string, long long>, compar> bestTeams;
    for (int i = 0; i < q; ++i) {
        std::string str;
        std::cin >> str;
        if (str == "show") {
            if (bestTeams.empty()) {
                std::cout << 0 << "\n";
            } else {
                int count = 0;
                std::string result;
                std::string temp;
                for (const auto &team: bestTeams) {
                    if (bestTeams.size() < L) { break; }
                    if (bestTeams.size() - L < count) { break; }
                    if (count == R - L + 1) { break; }
                    temp = team.first + "\n" + result;
                    result = temp;
                    ++count;
                }
                std::cout << count << "\n" << result;
            }
        } else {
            int tasks, fine;
            std::cin >> tasks >> fine;
            if (tasks > 0) {
                std::map<std::string, long long> scores;
                auto it = scores.find(str);
                if (it != scores.end()) {
                    long long res = it->second;
                    auto find_ = bestTeams.find(std::pair<std::string, long long>(str, res));
                    if (find_ != bestTeams.end()) {
                        bestTeams.erase(find_);
                    }
                }
                scores[str] = tasks * 100000 - fine;
                bestTeams.insert(make_pair(str, tasks * 100000 - fine));
                if (bestTeams.size() > (R)) {
                    bestTeams.erase((bestTeams.begin()));
                }
            }
        }
    }

}