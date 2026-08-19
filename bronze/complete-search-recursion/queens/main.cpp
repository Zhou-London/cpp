
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <vector>

// * perm solution
int perm() {

  std::ifstream fin("queens.in");
  std::ofstream fout("queens.out");

  constexpr int N = 8;
  std::vector<std::vector<int>> matrix(N, std::vector<int>(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      fin >> matrix[i][j];
    }
  }

  // One row can only have one queen
  std::vector<int> queens{0, 1, 2, 3, 4, 5, 6, 7};

  int count = 0;
  auto search = [&]() -> void {
    do {
      bool available = true;

      // * Check if queen is blocked
      for (int i = 0; i < queens.size(); ++i) {
        int q_row = queens[i];
        int q_col = i;

        if (matrix[q_row][q_col] == '*') {
          available = false;
          break;
        }
      }

      // * Check the diagonals from the top-left to the bottom-right
      std::vector<bool> taken(N * 2 - 1);
      for (int c = 0; c < N; c++) {
        if (taken[c + queens[c]]) {
          available = false;
          break;
        }
        taken[c + queens[c]] = true;
      }

      // * Check the diagonals from the top-right to the bottom-left
      taken = std::vector<bool>(N * 2 - 1);
      for (int c = 0; c < N; c++) {
        if (taken[queens[c] - c + N - 1]) {
          available = false;
          break;
        }
        taken[queens[c] - c + N - 1] = true;
      }

      if (available)
        ++count;

    } while (std::next_permutation(queens.begin(), queens.end()));
  };

  search();
  fout << count << "\n";

  return 0;
}

// * backtracking solution
int backtrack() {
  std::ifstream fin("queens.in");
  std::ofstream fout("queens.out");

  constexpr int N = 8;
  std::vector<std::vector<int>> matrix(N, std::vector<int>(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      fin >> matrix[i][j];
    }
  }

  int count = 0;

  std::vector<bool> rows_taken(N);
  std::vector<bool> diag1(2 * N - 1);
  std::vector<bool> diag2(2 * N - 1);

  auto search = [&](auto &&self, int c = 0) -> void {
    if (c == N) {
      ++count;
      return;
    }

    for (int r = 0; r < N; ++r) {
      // * Check row and diag
      bool diag_taken = diag1[r + c] || diag2[r - c + N - 1];
      if (diag_taken || rows_taken[r] || matrix[r][c] == '*')
        continue;

      // * Update record
      rows_taken[r] = true;
      diag1[r + c] = true;
      diag2[r - c + N - 1] = true;

      self(self, c + 1);

      rows_taken[r] = false;
      diag1[r + c] = false;
      diag2[r - c + N - 1] = false;
    }
  };

  search(search);

  fout << count << "\n";

  return 0;
}

int main() {
  backtrack();

  return 0;
}