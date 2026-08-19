
#include <cinttypes>
#include <iostream>
#include <unordered_map>
#include <vector>
int main() {

  int n = 5;
  std::vector<int> vec(n);

  for (int i = 0; i < n; ++i) {
    vec[i] = i; // 0, 1, 2, 3, 4
  }

  std::vector<std::vector<int>> subsets;
  std::vector<int> subset;

  // * Naive: No deduplication
  auto search_naive = [&](auto &&self, int k) -> void {
    if (k == n) {
      subsets.push_back(subset);
      return;
    }

    self(self, k + 1);
    subset.push_back(vec[k]);
    self(self, k + 1);
    subset.pop_back();
  };

  // * Bit mask approach
  auto search_bm = [&](auto &&self) -> void {
    for (int bm = 0; bm < (1 << n); ++bm) {
      subset.clear();

      for (int i = 0; i < n; ++i) {
        if (bm & (1 << i)) {
          subset.push_back(vec[i]);
        }
      }

      subsets.push_back(subset);
    }
  };

  // * Backtracking + deduplication
  std::unordered_map<int, int> freq;
  for (const auto &val : vec) {
    freq[val]++;
  }

  auto search_dd = [&](auto &&self, int idx) -> void {
    if (idx == n) {
      subsets.push_back(subset);
      return;
    }

    auto cnt = freq[vec[idx]];

    // Choose 0, 1, 2 or ... numbers of this element
    for (int i = 0; i <= cnt; ++i) {
      self(self, idx + 1);
      subset.push_back(vec[idx]);
    }

    for (int i = 0; i <= cnt; ++i) {
      subset.pop_back();
    }
  };

  // search_naive(search_naive, 0);
  // search_bm(search_bm);
  search_dd(search_dd, 0);

  std::cout << "Size: " << subsets.size() << "\n";
  for (const auto &v : subsets) {
    for (const auto &i : v)
      std::cout << i;

    std::cout << "\n";
  }
}