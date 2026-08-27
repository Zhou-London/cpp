

// * https://codeforces.com/contest/1783/problem/C
// ? Greedy
// ! 1700

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int T;
  std::cin >> T;

  while (T--) {
    int n;
    long long m;

    std::cin >> n >> m;

    struct Ppl {
      int wait;
      int idx;
    };

    std::vector<int> a(n); // original array
    std::vector<Ppl> ppl(n);
    for (int i = 0; i < n; ++i) {
      int wait;
      std::cin >> wait;

      a[i] = wait;
      ppl[i] = {wait, i};
    }

    std::sort(ppl.begin(), ppl.end(),
              [&](const Ppl &a, const Ppl &b) { return a.wait < b.wait; });

    // * 1. Greedy
    long long cost = 0;
    int wins = 0;
    while (wins < n && cost + ppl[wins].wait <= m) {
      cost += ppl[wins].wait; // ! Check the order
      ++wins;
    }

    // * 2. Check "next position guy"

    if (wins == n) {
      std::cout << 1 << "\n";
      continue;
    }

    bool included = false;
    for (int i = 0; i < wins; ++i) {
      if (ppl[i].idx == wins) {
        included = true;
        break;
      }
    }

    if (!included && wins > 0 && cost - ppl[wins - 1].wait + a[wins] <= m) {
      included = true;
    }

    std::cout << (included ? n - wins : n - wins + 1) << "\n";
  }

  return 0;
}