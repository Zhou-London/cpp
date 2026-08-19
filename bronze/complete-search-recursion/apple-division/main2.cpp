

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <vector>

int search(const std::vector<int> &vec, const int n, int idx, int sum1,
           int sum2) {
  if (idx == n) {
    return abs(sum1 - sum2);
  }

  return std::min(search(vec, n, idx + 1, sum1 + vec[idx], sum2),
                  search(vec, n, idx + 1, sum1, sum2 + vec[idx]));
}

int main() {
  std::ifstream fin("apple.in");
  std::ofstream fout("apple.out");

  int n;
  fin >> n;

  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    fin >> vec[i];
  }

  fout << search(vec, n, 0, 0, 0);
}