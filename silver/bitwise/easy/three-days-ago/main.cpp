

// * https://atcoder.jp/contests/abc295/tasks/abc295_d
// ? Bitwise

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  std::string S;
  std::cin >> S;
  int n = S.size();

  int mask = 0;
  std::vector<int> cnt(1024, 0);
  cnt[0] = 1;
  long long ans = 0;

  for (int i = 0; i < n; ++i) {
    mask ^= 1 << (S[i] - '0'); // * Flip ith bit: XOR with 0 always changes nothing
    ans += cnt[mask];
    ++cnt[mask];
  }

  std::cout << ans << "\n";
  return 0;
}