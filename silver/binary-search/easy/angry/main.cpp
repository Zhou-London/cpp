

// https://usaco.org/index.php?page=viewproblem2&cpid=594

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
int main() {
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  int N, K;
  std::cin >> N >> K;

  std::vector<long long> haybales(N);
  for (int i = 0; i < N; ++i)
    std::cin >> haybales[i];

  std::sort(haybales.begin(), haybales.end());

  auto check = [&](const long long R) {
    long long start = haybales[0]; // x - R
    int shot = 1;

    for (int i = 0; i < N; ++i) {
      int end = start + 2 * R; // x + R

      if (haybales[i] > end) {
        start = haybales[i];
        ++shot; // Need another shot
      }
    }

    return shot <= K;
  };

  long long lower = 1;
  long long upper = haybales[N - 1] - haybales[0];

  while (lower < upper) {
    int mid = lower + (upper - lower) / 2;

    if (check(mid)) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }

  std::cout << lower << "\n";
  return 0;
}