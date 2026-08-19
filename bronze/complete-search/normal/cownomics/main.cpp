

#include <fstream>
#include <vector>
int main() {

  std::ifstream fin("cownomics.in");
  std::ofstream fout("cownomics.out");

  int N, M;
  fin >> N >> M;

  std::vector<std::vector<char>> spotty(N, std::vector<char>(M));
  std::vector<std::vector<char>> plain(N, std::vector<char>(M));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      fin >> spotty[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      fin >> plain[i][j];
    }
  }

  int res = 0;

  // Fix column
  for (int p = 0; p < M; ++p) {
    bool potential = true;

    // Search all pairs
    for (int spot = 0; spot < N; ++spot) {
      char sg = spotty[spot][p];

      // If happens the same, not potenial
      for (int pn = 0; pn < N; ++pn) {
        char pg = plain[pn][p];
        if (sg == pg) {
          potential = false;
          break;
        }
      }
    }

    if (potential)
      ++res;
  }

  fout << res << "\n";

  return 0;
}