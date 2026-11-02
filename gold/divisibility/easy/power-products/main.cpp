

// * https://codeforces.com/contest/1225/problem/D
// ? Divisibility, Hashing

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> input(n);
  std::unordered_map<int, int> map; // Value and Occurance
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> input[i];

    // Factorization
    std::vector<std::pair<int, int>> factors;
    int base = input[i];
    for (int p = 2; p * p <= base; ++p) {
      if (base % p == 0) {
        int cnt = 0;
        while (base % p == 0) {
          ++cnt;
          base /= p;
        }

        factors.push_back({p, cnt});
      }
    }

    if (base > 1) {
      factors.push_back({base, 1});
    }

    // Evaluate needed and Normalize
    int need = 1;
    int norm = 1;
    bool valid_need = true;
    for (auto &[factor, cnt] : factors) {
      // ! Use modulo
      int diff = (k - cnt % k) % k;
      while (diff > 0) {
        // ! Check if need overflow
        if (need > 100'000 / factor) {
          valid_need = false;
          break;
        }
        need *= factor;
        --diff;
      }

      // Normalize
      int mod_k = cnt % k;
      while (mod_k > 0) {
        norm *= factor;
        --mod_k;
      }
    }

    // Check how many values match
    if (valid_need) {
      auto it = map.find(need);
      if (it != map.end()) {
        ans += it->second;
      }
    }

    ++map[norm];
  }

  std::cout << ans << "\n";
  return 0;
}