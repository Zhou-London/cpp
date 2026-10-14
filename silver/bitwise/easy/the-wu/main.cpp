

// * https://codeforces.com/contest/1017/problem/D
// ? Bitwise
// ! >2000

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<int> w(n);
  for (int i = 0; i < n; ++i)
    std::cin >> w[i];

  int full = 4096;
  std::vector<int> cnt(full, 0);

  // ! Horner
  auto toMask = [](std::string &s) {
    int x = 0;
    for (char c : s) {
      x = x * 2 + (c - '0');
    }
    return x;
  };

  for (int i = 0; i < m; ++i) {
    std::string s;
    std::cin >> s;
    ++cnt[toMask(s)];
  }

  std::vector<long long> val(full, 0);
  for (int x = 0; x < full; ++x) {
    val[x] = 0;

    // * Check 0 bit, if yes then add value
    for (int i = 0; i < n; ++i) {
      if (((x >> (n - 1 - i)) & 1) == 0)
        val[x] += w[i];
    }
  }

  // * f[t][k] := how many strings s.t. when quering string t, Wu is at k
  std::vector<std::vector<long long>> f(full, std::vector<long long>(101));
  for (int t = 0; t < full; ++t) {
    // ! Do not iterate value
    for (int s = 0; s < full; ++s) {
      long long v = val[s ^ t];
      if (v <= 100) {
        f[t][v] += cnt[s];
      }
    }
  }

  // * f[t][k] := how many strings s.t. when quering string t, Wu is smaller
  // than k
  for (int t = 0; t < full; ++t) {
    for (int v = 1; v <= 100; ++v) {
      f[t][v] += f[t][v - 1]; // ! Don't touch t since not diagnoal
    }
  }

  for (int i = 0; i < q; ++i) {
    std::string t;
    int k;
    std::cin >> t >> k;
    int t_int = toMask(t);

    std::cout << f[t_int][k] << "\n";
  }

  return 0;
}