

// * https://codeforces.com/contest/1398/problem/C
// ? PSum, HashMap

#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
int main() {
  freopen("good.in", "r", stdin);
  freopen("good.out", "w", stdout);

  int T;
  std::cin >> T;
  while (T--) {
    int N;
    std::cin >> N;

    std::vector<int> vec(N);
    std::string str;

    for (int i = 0; i < N; ++i) {
      vec[0] = str[0] - '0';
    }

    std::vector<long long> psum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      psum[i] = psum[i - 1] + vec[i - 1];
    }
  }
}