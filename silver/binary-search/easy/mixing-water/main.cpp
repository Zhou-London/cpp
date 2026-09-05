

// * https://codeforces.com/problemset/problem/1359/C
// ? Mathematics

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  long long T;
  std::cin >> T;

  while (T--) {
    long long h, c, t;
    std::cin >> h >> c >> t;

    if (2 * t <= h + c) {
      std::cout << "2\n";
      continue;
    }

    auto Top = [&](long long k) {
      return ((k + 1) * h + k * c) - t * (2 * k + 1); // !
    };
    auto Bott = [&](long long k) { return (2 * k + 1); };

    long long k0 = (h - t) / (2 * t - h - c);

    long long f0 = std::abs(Top(k0)) * Bott(k0 + 1);
    long long f1 = std::abs(k0 + 1) * Bott(k0);

    long long k = f0 <= f1 ? k0 : k0 + 1;

    std::cout << 2 * k + 1 << "\n";
  }

  return 0;
}