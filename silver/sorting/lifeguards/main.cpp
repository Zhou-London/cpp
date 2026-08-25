
// * https://usaco.org/index.php?page=viewproblem2&cpid=786
// ! ~1900
// ? Psum, Diff array, Cooord compress, Intervals

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<std::pair<int, int>> times(N);
  std::vector<int> vertex;

  for (int i = 0; i < N; ++i) {
    int a, b;
    std::cin >> a >> b;

    times[i] = {a, b};
    vertex.push_back(a);
    vertex.push_back(b);
  }

  std::sort(vertex.begin(), vertex.end());
  vertex.erase(std::unique(vertex.begin(), vertex.end()), vertex.end());

  auto idx = [&](long long original) {
    return std::lower_bound(vertex.begin(), vertex.end(), original) -
           vertex.begin();
  };

  int M = vertex.size();

  std::vector<long long> diff(M + 1);

  for (int i = 0; i < N; ++i) {
    auto &time = times[i];
    diff[idx(time.first)] += 1;
    diff[idx(time.second)] -= 1;
  }

  for (int i = 0; i < M; ++i) {
    diff[i + 1] += diff[i];
  }

  long long total = 0;
  std::vector<long long> uniq(M + 1);

  for (int i = 0; i < M - 1; ++i) {
    if (diff[i] > 0) // ! If there is people in this interval
      total += (vertex[i + 1] - vertex[i]);

    if (diff[i] == 1) // ! Consider when diff[i] != 1, uniq has not been init
      uniq[i + 1] = uniq[i] + vertex[i + 1] - vertex[i];
    else
      uniq[i + 1] = uniq[i];
  }

  long long min_uniq = LLONG_MAX;
  for (int i = 0; i < N; ++i) {
    auto &time = times[i]; // Check every one's "unique contribution"
    min_uniq =
        std::min(min_uniq, uniq[idx(time.second)] - uniq[idx(time.first)]);
  }

  std::cout << total - min_uniq << "\n";

  return 0;
}