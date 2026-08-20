
// * https://codeforces.com/contest/782/problem/B
// ? Binary search, interval

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
int main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

  long long n;

  std::cin >> n;

  struct Friend {
    long long pos;
    long long v;
  };

  std::vector<Friend> friends(n);

  for (int i = 0; i < n; ++i) {
    long long pos;
    std::cin >> pos;
    friends[i].pos = pos;
  }

  for (int i = 0; i < n; ++i) {
    long long v;
    std::cin >> v;
    friends[i].v = v;
  }

  // ! Check if exists overlapping interval
  auto Check = [&](const double T) {
    double UP = std::numeric_limits<double>::max();
    double DOWN = std::numeric_limits<double>::min();

    for (const auto &f : friends) {
      double f_up = (double)f.pos + f.v * T;
      double f_down = (double)f.pos - f.v * T;

      UP = std::min(f_up, UP);
      DOWN = std::max(f_down, DOWN);
    }

    return DOWN <= UP;
  };

  double lower = 0.0;
  double upper = (double)std::numeric_limits<double>::max(); // ! High upper limit

  while (upper - lower > 1e-6) {
    double mid = lower + (upper - lower) / 2;

    if (Check(mid)) {
      upper = mid;
    } else {
      lower = mid;
    }
  }

  std::cout << upper << "\n";
  return 0;
}