

// * https://atcoder.jp/contests/abc365/tasks/abc365_e
// ? Bitwise, Prefix sum

#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int N;
  std::cin >> N;

  std::vector<int> nums(N + 1);
  for (int i = 1; i <= N; ++i)
    std::cin >> nums[i];

  std::vector<long long> psum_xor(N + 1, 0);
  std::vector<long long> psum_add(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    psum_xor[i] = psum_xor[i - 1] ^ nums[i];
    psum_add[i] = psum_add[i - 1] + nums[i];
  }

  long long ans = 0;
  for (int k = 0; k <= 26; ++k) {
    long long c1 = 0; // * Count how many 1
    for (int i = 0; i <= N; ++i) {
      if ((psum_xor[i] >> k) & 1) {
        ++c1;
      }
    }
    long long c0 = N + 1 - c1; // * Count how many 0

    // * Pair a 0 with a 1
    ans += c0 * c1 * (1 << k); // ! 2^n = (1 << n)
  }

  // Minus the unary array such as [A1,A1], [A2,A2]
  ans -= psum_add[N];
  std::cout << ans << "\n";
  return 0;
}