

// * https://codeforces.com/contest/1872/problem/E
// ? Bitwise, Psum

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> input(n + 1);
    for (int i = 1; i <= n; ++i)
      std::cin >> input[i];

    std::string s;
    std::cin >> s;

    std::vector<long long> psum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      psum[i] = psum[i - 1] ^ input[i];
    }

    long long X1 = 0;
    for (int i = 1; i <= n; ++i)
      if (s[i - 1] == '1') // ! char is almost always true
        X1 ^= input[i];

    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
      int icode;
      std::cin >> icode;
      if (icode == 1) {
        int l, r;
        std::cin >> l >> r;
        X1 ^= psum[r] ^ psum[l - 1];
      } else {
        int g;
        std::cin >> g;
        std::cout << (g ? X1 : X1 ^ psum[n]) << " ";
      }
    }

    std::cout << "\n";
  }

  return 0;
}