

// * https://usaco.org/index.php?page=viewproblem2&cpid=763
// ? Sorted map, Sorting, Simulation

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  int N, G;
  std::cin >> N >> G;

  struct Log {
    int day;
    int id;
    long long delta;
  };

  std::vector<Log> logs(N);
  for (int i = 0; i < N; ++i) {
    int day, id, delta;
    std::string str;
    std::cin >> day >> id >> str;

    delta = std::stoi(str.substr(1, str.size() - 1));
    if (str[0] == '-')
      delta *= -1;

    logs[i] = {day, id, delta};
  }

  // Sort by date
  std::sort(logs.begin(), logs.end(),
            [](const Log &a, const Log &b) { return a.day < b.day; });

  std::unordered_map<long long, long long> milk;
  std::multiset<long long> values;
  int ans = 0;

  for (int i = 0; i < N; ++i) {
    auto &log = logs[i];

    if (milk.find(log.id) == milk.end()) {
      milk[log.id] = G;
      values.insert(G);
    }

    long long old_top = std::max<long long>(G, *values.rbegin());
    int old_count = old_top == G ? INT_MAX : values.count(old_top);
    bool in_before = milk[log.id] == old_top;

    values.erase(values.find(milk[log.id])); // Erase the old
    milk[log.id] += log.delta;
    values.insert(milk[log.id]);

    long long new_top = std::max<long long>(G, *values.rbegin());
    int new_count = new_top == G ? INT_MAX : values.count(new_top);
    bool in_after = milk[log.id] == new_top;

    if (!in_before && !in_after) // Not on board
      continue;
    else if (in_before != in_after) // New on board
      ++ans;
    else if (in_before &&
             in_after) { // Always on board, but is there new entrant?
      if (old_count == 1 && new_count == 1)
        continue;
      else
        ++ans;
    }
  }

  std::cout << ans << "\n";
  return 0;
}