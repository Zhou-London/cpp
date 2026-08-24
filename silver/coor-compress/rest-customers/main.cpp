
// * https://cses.fi/problemset/task/1619
// ? Diff arr, Prefix sum, Coord compress

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  // ! Keep original
  std::vector<std::pair<long long, long long>> records(n);
  std::vector<long long> vertexs;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    std::cin >> a >> b;
    vertexs.push_back(a);
    vertexs.push_back(b);

    records[i] = {a, b};
  }

  // ! Sort
  std::sort(vertexs.begin(), vertexs.end());
  vertexs.erase(std::unique(vertexs.begin(), vertexs.end()), vertexs.end());

  auto idx = [&](long long original) {
    return std::lower_bound(vertexs.begin(), vertexs.end(), original) -
           vertexs.begin();
  };

  int M = vertexs.size();

  std::vector<long long> diff(M + 1);

  for (int i = 0; i < n; ++i) {
    const auto &record = records[i];

    diff[idx(record.first)] += 1;
    diff[idx(record.second)] -= 1;
  }

  long long max = LLONG_MIN;
  for (int i = 0; i < M; ++i) {
    diff[i + 1] += diff[i];
    max = std::max(diff[i], max); // ! Check 0
    max = std::max(diff[i + 1], max);
  }

  std::cout << max << "\n";
  return 0;
}