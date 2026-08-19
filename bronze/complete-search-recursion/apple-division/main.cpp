#include <algorithm>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <vector>
int main() {

  std::ifstream fin("apple.in");
  std::ofstream fout("apple.out");

  int n;
  fin >> n;

  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i)
    fin >> vec[i];

  int ans = INT_MAX;

  // Use bitmap to generate all subsets
  // https://usaco.guide/CPH.pdf#page=57 
  for (int b = 0; b < (1 << n); ++b) {
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < n; ++i) {
      if (b & (1 << i)) {
        sum1 += vec[i];
      } else {
        sum2 += vec[i];
      }
    }

    ans = std::min(ans, abs(sum1 - sum2));
  }

  fout << ans << "\n";

  return 0;
}