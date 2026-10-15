

// * https://codeforces.com/contest/1851/problem/F
// ? Bitwise, ad-hoc

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;

    struct Martian {
      int val;
      int idx;
    };
    std::vector<Martian> input(n);
    for (int i = 0; i < n; ++i) {
      int val;
      std::cin >> val;
      input[i] = {val, i};
    }

    std::sort(input.begin(), input.end(),
              [](Martian a, Martian b) { return a.val < b.val; });

    // * Find ans: neg of minimal xor pair
    int min_xor = INT_MAX;
    int ai = 0;
    int iy = 0;
    int jy = 0;
    for (int i = 0; i < n - 1; ++i) {
      int adj_xor = input[i].val ^ input[i + 1].val;
      if (adj_xor < min_xor) {
        min_xor = adj_xor;
        ai = input[i].val;
        iy = input[i].idx;
        jy = input[i + 1].idx;
      }
    }

    // * Imply x
    int x = ((1 << k) - 1) ^ ai;

    if (iy > jy) {
      std::swap(iy, jy);
    }

    std::cout << iy + 1 << " " << jy + 1 << " " << x << "\n";
  }
  return 0;
}