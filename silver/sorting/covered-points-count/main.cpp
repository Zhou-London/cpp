

// * https://codeforces.com/problemset/problem/1000/C
// ! 1700
// ? Psum, Diff array, Coord compress, Intervals

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::pair<long long, long long>> points(n);
  std::vector<long long> vertexs;

  for (int i = 0; i < n; ++i) {
    long long l, r;
    std::cin >> l >> r;

    points[i] = {l, r};
    vertexs.push_back(l);
    vertexs.push_back(r + 1); // ! R is inclusive
  }

  std::sort(vertexs.begin(), vertexs.end());
  vertexs.erase(std::unique(vertexs.begin(), vertexs.end()), vertexs.end());

  auto idx = [&](long long original) { // ! Overflow
    return std::lower_bound(vertexs.begin(), vertexs.end(), original) -
           vertexs.begin();
  };

  size_t M = vertexs.size();
  std::vector<long long> diff(M + 1, 0);

  for (int i = 0; i < n; ++i) {
    auto &point = points[i];
    diff[idx(point.first)] += 1;
    diff[idx(point.second + 1)] -= 1; // ! R + 1 since R is inclusive
  }

  for (int i = 0; i < M; ++i)
    diff[i + 1] += diff[i];

  std::vector<long long> count(n + 1, 0);
  for (int i = 0; i < M - 1;
       ++i) { // ! Between M vertex, there are M - 1 intervals
    if (diff[i] > 0)
      count[diff[i]] += vertexs[i + 1] - vertexs[i];
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << count[i] << " ";
  }

  std::cout << "\n";

  return 0;
}