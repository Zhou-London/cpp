

// * https://codeforces.com/contest/1398/problem/C
// ? PSum, HashMap

#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  // freopen("good.in", "r", stdin);
  // freopen("good.out", "w", stdout);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;

    std::string str;
    std::cin >> str;

    std::vector<int> vec(n + 1);
    for (int i = 0; i < n; ++i) {
      vec[i + 1] = str[i] - '0';
    }

    std::vector<long long> psum(n + 1);
    for (int i = 1; i <= n; ++i) {
      psum[i] = psum[i - 1] + vec[i];
    }

    // D[i] = psum[i] - i
    std::unordered_map<long long, long long> count_map;
    for (int i = 0; i <= n; ++i) {
      long long D = psum[i] - i;
      ++count_map[D];
    }

    long long ans = 0;
    for (auto &[_, v] : count_map) {
      ans += v * (v - 1) / 2;
    }

    std::cout << ans << "\n";
  }

  return 0;
}