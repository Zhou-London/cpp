
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  auto& fin = std::cin;
  auto& fout = std::cout;

//   std::ifstream fin("reflection.in");
//   std::ofstream fout("reflection.out");

  int N, U;
  fin >> N >> U;

  std::vector<std::string> matrix(N);

  for (int i = 0; i < N; ++i) {
    fin >> matrix[i];
  }

  auto Group = [&](int r, int c) -> int {
    // Vertical
    int r_v = r;
    int c_v = N - 1 - c;

    // Central
    int r_c = N - 1 - r;
    int c_c = N - 1 - c;

    // Horizontal
    int r_h = N - 1 - r;
    int c_h = c;

    int dot = 0;
    int sharp = 0;

    if (matrix[r_v][c_v] == '.')
      ++dot;
    else
      ++sharp;

    if (matrix[r_c][c_c] == '.')
      ++dot;
    else
      ++sharp;

    if (matrix[r_h][c_h] == '.')
      ++dot;
    else
      ++sharp;

    if (matrix[r][c] == '.')
      ++dot;
    else
      ++sharp;

    return 4 - std::max(dot, sharp);
  };

  // Upper-left corner
  int sum = 0;
  for (int i = 0; i < N / 2; ++i) {
    for (int j = 0; j < N / 2; ++j) {
      sum += Group(i, j);
    }
  }

  fout << sum << "\n";

  for (int i = 0; i < U; ++i) {
    int r_f, c_f;
    fin >> r_f >> c_f;

    --r_f;
    --c_f;

    int before = Group(r_f, c_f);
    sum -= before;

    matrix[r_f][c_f] = (matrix[r_f][c_f] == '.' ? '#' : '.');

    int after = Group(r_f, c_f);
    sum += after;

    fout << sum << "\n";
  }

  return 0;
}