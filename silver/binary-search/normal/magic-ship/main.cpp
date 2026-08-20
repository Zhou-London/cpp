
// * https://codeforces.com/problemset/problem/1117/C
// ? Binary search, prefix sum, modulo

#include <array>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
int main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

  long long x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  int n;
  std::string s;
  std::cin >> n >> s;

  // [0]: x, [1]:y
  // ! Only store delta
  std::vector<std::array<long long, 2>> psum(n + 1, {0, 0});

  for (int i = 0; i < n; ++i) {
    psum[i + 1] = psum[i]; // ! Update the coords
    if (s[i] == 'U') {
      psum[i + 1][1] = psum[i][1] + 1;
    } else if (s[i] == 'D') {
      psum[i + 1][1] = psum[i][1] - 1;
    } else if (s[i] == 'R') {
      psum[i + 1][0] = psum[i][0] + 1;
    } else if (s[i] == 'L') {
      psum[i + 1][0] = psum[i][0] - 1;
    }
  }

  // ! Periodic
  auto Query = [&](const long long days) {
    long long cycles = days / n;
    long long rem = days % n;

    std::array<long long, 2> base;
    base[0] = x1 + cycles * psum[n][0] + psum[rem][0];
    base[1] = y1 + cycles * psum[n][1] + psum[rem][1];

    return base;
  };

  auto Check = [&](const long long days) {
    auto start = Query(days);
    long long dist = std::abs(x2 - start[0]) + std::abs(y2 - start[1]);

    return dist <= days;
  };

  long long lower = 0;
  long long upper = LLONG_MAX;

  while (lower < upper) {
    long long mid = lower + (upper - lower) / 2;

    if (Check(mid)) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }

  if (upper == LLONG_MAX) {
    std::cout << -1 << "\n";
    return 1;
  };

  std::cout << upper << "\n";
  return 0;
}