#include <iostream>
#include <unordered_map>
#include <vector>

// * Naive version
struct Perm {

  Perm(const std::vector<int> &vec) : vec(vec), n(vec.size()) {
    chosen = std::vector<bool>(n);
  };

  int n;
  const std::vector<int> &vec;

  std::vector<std::vector<int>> perms;
  std::vector<int> perm;
  std::vector<bool> chosen;

  void search() {
    if (perm.size() == n) {
      perms.push_back(perm);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (chosen[i])
        continue;

      chosen[i] = true;
      perm.push_back(vec[i]);
      search();
      chosen[i] = false;
      perm.pop_back();
    }
  }
};

// * Deduplication
struct Perm_dd {
  Perm_dd(const std::vector<int> &vec) : vec(vec), n(vec.size()) {
    for (const auto &val : vec) {
      freq[val]++;
    }
  };

  const std::vector<int> &vec;
  int n;

  std::vector<std::vector<int>> perms;
  std::unordered_map<int, int> freq;

  void search(std::vector<int> path = {}) {
    if (path.size() == n) {
      perms.push_back(path);
      return;
    }

    for (auto &[val, cnt] : freq) {
      if (cnt > 0) {
        cnt--;
        path.push_back(val);

        search(path);

        path.pop_back();
        cnt++;
      }
    }
  }
};

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};

  Perm_dd perm(vec);

  perm.search();

  std::cout << perm.perms.size() << "\n";
}