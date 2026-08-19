

// https://usaco.org/index.php?page=viewproblem2&cpid=858

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);

  int N, M, C;
  std::cin >> N >> M >> C;

  std::vector<long long> times(N);
  for (int i = 0; i < N; ++i)
    std::cin >> times[i];

  std::sort(times.begin(), times.end());

  auto check = [&](const long long x) {
    int bus = 1; // ! Count the first
    int first = 0;

    for (int i = 0; i < N; ++i) {
      if ((times[i] - times[first] > x) ||
          (i - first + 1 > C)) { // ! Can equal to C
        first = i;
        ++bus;
      }
    }

    return bus <= M;
  };

  long long lower = 0;
  long long upper = times[N - 1] - times[0]; // ! Upper bound

  while (lower < upper) {
    long long mid = lower + (upper - lower) / 2; // ! Use long long
    if (check(mid)) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }

  std::cout << upper << "\n";
}