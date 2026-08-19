
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int main() {
  std::ifstream fin("circlecross.in");
  std::ofstream fout("circlecross.out");

  // [0] -> entry, [1] -> exit
  std::vector<std::vector<int>> points(26, std::vector<int>(2, -1));
  std::string raw;
  fin >> raw;

  for (int i = 0; i < 52; ++i) {
    char c = raw[i];

    // Record entry and exit
    int idx = c - 'A';
    if (points[idx][0] == -1)
      points[idx][0] = i;
    else
      points[idx][1] = i;
  }

  int res = 0;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (i == j)
        continue;

      const auto &A = points[i];
      const auto &B = points[j];

      // * core
      if (B[0] > A[0] && B[0] < A[1] && B[1] > A[1])
        ++res;
    }
  }

  fout << res << "\n";
}