

// * https://codeforces.com/contest/862/problem/E
// ? Binary Search + Alt Prefix Sum + Mathematics

#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);

  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<long long> a(n);
  std::vector<long long> b(m);

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  // sigma A
  auto QueryA = [&]() {
    long long sum = 0;
    for (int i = 0, sign = -1; i < n; ++i) {
      sign *= -1;
      sum += sign * a[i];
    }

    return sum;
  };

  // Preprocess B
  std::vector<long long> altB(m + 1);
  for (int i = 0, sign = -1; i < m; ++i) {
    sign *= -1;
    altB[i + 1] = altB[i] + sign * b[i];
  }

  // sigma B
  auto QueryB = [&](const int j) {
    int sign;
    if ((j + 1) % 2 == 0) {
      sign = -1;
    } else {
      sign = 1;
    }

    return sign * (altB[j + n] - altB[j]); // ! [j + n] - [j]
  };

  // The delta of A after update
  auto deltaA = [&](const long long x, long long l, long long r) {
    return (r - l + 1) % 2 == 0 ? 0 : (l % 2 == 1 ? x : -x);
  };

  long long A = QueryA();
  std::vector<long long> Bj;

  // Sort all possible B, then binary search
  for (int j = 0; j <= m - n; ++j) {
    Bj.push_back(QueryB(j));
  }
  std::sort(Bj.begin(), Bj.end());

  // Either lower bound or (lower bound - 1) is the closest Bj
  /// ! Technique of "finding the closest"
  auto Query = [&]() {
    auto pos = std::lower_bound(Bj.begin(), Bj.end(), A); // ! Check valid
    long long best = LLONG_MAX;

    if (pos != Bj.end())
      best = std::min(best, std::abs(*pos - A));

    if (pos != Bj.begin())
      best = std::min(best, std::abs(*(pos - 1) - A));
  };

  Query();

  for (int i = 0; i < q; ++i) {
    long long l, r, x;
    std::cin >> l >> r >> x;

    A += deltaA(x, l, r);

    Query();
  }

  return 0;
}