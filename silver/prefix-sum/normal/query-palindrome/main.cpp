
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int main() {
  // std::ifstream fin("palindrome.in");
  // std::ofstream fout("palindrome.out");

  auto &fin = std::cin;
  auto &fout = std::cout;

  std::string s;
  fin >> s;

  int q;
  fin >> q;

  std::vector<std::vector<bool>> isPal(s.size(), std::vector<bool>(s.size()));
  std::vector<std::vector<int>> cnt(s.size() + 1,
                                    std::vector<int>(s.size() + 1));

  // * Build isPal by "recursion"
  // ! i from right to left
  for (int i = s.size() - 1; i >= 0; --i) {
    for (int j = i; j < s.size(); ++j) {
      if (i == j)
        isPal[i][j] = true;
      else if (j == i + 1 && s[i] == s[j])
        isPal[i][j] = true;
      else if (j > i + 1 && s[i] == s[j] && isPal[i + 1][j - 1]) {
        isPal[i][j] = true;
      }
    }
  }

  // * Build prefix sum
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < s.size(); ++j) {
      cnt[i + 1][j + 1] =
          cnt[i][j + 1] + cnt[i + 1][j] - cnt[i][j] + (isPal[i][j] ? 1 : 0);
    }
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    fin >> l >> r;

    // ! (start < r, enda < r) - (start < l - 1, end < r) = (start >= l, end <=
    // r)
    fout << cnt[r][r] - cnt[l - 1][r] << "\n";
  }

  return 0;
}