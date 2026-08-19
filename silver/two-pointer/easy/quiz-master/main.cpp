
#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

const int M = 1e5;
std::vector<int> factors[M + 1];

int main() {
  // freopen("quiz.in", "r", stdin);
  // freopen("quiz.out", "w", stdout);

  // * Precompute factors
  for (int i = 1; i <= M; ++i) {
    for (int j = i; j <= M; j += i) { // j = i, 2i, 3i, ...
      factors[j].push_back(i);
    }
  }

  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<long long> input(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> input[i];
    }

    std::unordered_map<int, int> hash; // factor -> count

    std::sort(input.begin(), input.end());

    for (int f : factors[input[0]])
      if (f <= m)
        hash[f]++;

    long long ans = INT_MAX;
    int r = 0;
    for (int l = 0; l < n; ++l) {
      // move r
      while (r + 1 < n && hash.size() < m) {
        ++r;
        for (int f : factors[input[r]])
          if (f <= m)
            hash[f]++;
      }

      if (hash.size() >= m)
        ans = std::min(ans, input[r] - input[l]);

      // move l
      for (int f : factors[input[l]]) {
        if (f <= m) {
          hash[f]--;
          if (hash[f] <= 0)
            hash.erase(f);
        }
      }
    }
    std::cout << (ans == INT_MAX ? -1 : ans) << "\n";
  }

  return 0;
}