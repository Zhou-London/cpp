

// https://cses.fi/problemset/task/1620

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n;
  long t;

  std::cin >> n;
  std::cin >> t;

  std::vector<long long> times(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> times[i];
  }

  std::sort(times.begin(), times.end());

  auto check = [&](const long long T) { // ! Use long long
    long long exp = 0;
    for (int i = 0; i < n; ++i) {
      exp += T / times[i];

      if (exp >= t)
        return true; // ! Cut branch
    }

    return exp >= t;
  };

  long long lower = 1;
  long long upper = t * times[n - 1];

  while (lower < upper) {
    long long mid = lower + (upper - lower) / 2;

    if (check(mid)) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }

  std::cout << upper << "\n";
  return 0;
}