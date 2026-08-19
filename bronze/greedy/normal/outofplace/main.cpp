
#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>
int main() {

  std::ifstream fin("outofplace.in");
  std::ofstream fout("outofplace.out");

  int N;
  fin >> N;

  std::vector<int> heights(N);

  for (int i = 0; i < N; ++i)
    fin >> heights[i];

  int count = 0;

  auto sorted = heights;
  std::sort(sorted.begin(), sorted.end());

  // * Count difference
  for (int i = 0; i < N; ++i) {
    if (sorted[i] != heights[i])
      ++count;
  }

  fout << count - 1 << "\n";

  return 0;
}