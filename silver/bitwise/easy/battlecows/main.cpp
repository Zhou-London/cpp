

// * https://codeforces.com/contest/2185/problem/F
// ? Bitwise, Psum

#include <cstdio>
#include <iostream>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int T;
  std::cin >> T;
  while (T--) {
    int N, Q;
    std::cin >> N >> Q;

    int size = 1 << N;
    std::vector<int> skills(size);
    for (int i = 0; i < size; ++i) {
      std::cin >> skills[i];
    }

    std::vector<int> psum(size + 1, 0);
    for (int i = 1; i <= size; ++i) {
      psum[i] = psum[i - 1] ^ skills[i - 1];
    }
    auto Query = [&](int l, int r) { return psum[r] ^ psum[l]; };

    for (int i = 0; i < Q; ++i) {
      int p, x;
      std::cin >> p >> x;

      int ans = 0;

      for (int k = 0; k < N; ++k) {
        int s = 1 << k;      // ! Check arrow direction
        int b = (p - 1) / s; // ! Offset

        int block_l = b * s;
        int block_r = (b + 1) * s;
        int me = Query(block_l, block_r) ^ skills[p - 1] ^ x; // Needs adapt

        int o = b ^ 1;
        int opposite_l = o * s;
        int opposite_r = (o + 1) * s;

        int op = Query(opposite_l, opposite_r); // No need adapt

        if (me < op || (me == op && b % 2 != 0))
          ans += s;
      }

      std::cout << ans << "\n";
    }
  }

  return 0;
}