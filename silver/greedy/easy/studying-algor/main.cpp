

// * https://codeforces.com/gym/102951/problem/B
// ? Greedy

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int N, X;
  std::cin >> N >> X;

  std::vector<int> times(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> times[i];
  }

  std::sort(times.begin(), times.end());

  long long total = 0;
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    total += times[i];
    if (total > X)
      break;
    else
      ++ans;
  }

  std::cout << ans << "\n";

  return 0;
}