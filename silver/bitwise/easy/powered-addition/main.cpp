

// * https://codeforces.com/contest/1338/problem/A
// ? Bitwise

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;

    std::vector<int> input(n);
    for (int i = 0; i < n; ++i)
      std::cin >> input[i];

    long long need = 0;
    int l = 0;
    for (int r = 1; r < n; ++r) {
      if (input[r] > input[l]) {
        l = r;
      } else {
        need = std::max<long long>(
            need, input[l] - input[r]); // ! Take max not accumulation
      }
    }

    int T = 0;
    while ((1LL << T) - 1 < need)
      ++T;

    std::cout << T << "\n";
  }

  return 0;
}