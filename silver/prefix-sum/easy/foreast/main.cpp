
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int main() {
  //   std::ifstream fin("foreast.in");
  //   std::ofstream fout("foreast.out");

  auto &fin = std::cin;
  auto &fout = std::cout;

  int n, q;
  fin >> n >> q;

  std::vector<std::vector<long long>> psum(n + 1,
                                           std::vector<long long>(n + 1, 0));

  for (int i = 0; i < n; ++i) {
    std::string str;
    fin >> str;

    for (int j = 0; j < n; ++j) {
      int num = str[j] == '.' ? 0 : 1;

      // * Evaluate prefix sum
      psum[i + 1][j + 1] = psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + num;
    }
  }

  // * Evaluate range sum
  auto Query = [&](int r1, int c1, int r2, int c2) {
    return psum[r2][c2] - psum[r2][c1 - 1] - psum[r1 - 1][c2] +
           psum[r1 - 1][c1 - 1];
  };

  for (int i = 0; i < q; ++i) {
    int r1, c1, r2, c2;
    fin >> r1 >> c1 >> r2 >> c2;

    fout << Query(r1, c1, r2, c2) << "\n";
  }

  return 0;
}