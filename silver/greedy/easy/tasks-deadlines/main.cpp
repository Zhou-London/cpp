
// * https://cses.fi/problemset/task/1630
// ? Greedy

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> vec(n);
  for (int i = 0; i < n; ++i) {
    int a, d;
    std::cin >> a >> d;

    vec[i] = {a, d};
  }

  std::sort(vec.begin(), vec.end());

  long long time = 0;
  long long award = 0;
  for (int i = 0; i < n; ++i) {
    time += vec[i].first;
    award += vec[i].second - time;
  }

  std::cout << award << "\n";
  return 0;
}