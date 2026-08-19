
#include <fstream>
#include <iostream>
#include <vector>
int main() {
  //   std::ifstream fin("nusret.in");
  //   std::ofstream fout("nusret.out");
  auto &fin = std::cin;
  auto &fout = std::cout;

  int n, m;
  fin >> n >> m;

  std::vector<int> input(n);

  for (int i = 0; i < n; ++i) {
    fin >> input[i];
  }

  // Forward
  for (int i = 1; i < n; ++i) {
    int diff = input[i] - input[i - 1];
    if (diff > m) {
      input[i - 1] = input[i] - m;
    } else if (diff < -m) {
      input[i] = input[i - 1] - m;
    }
  }

  // Backward
  for (int i = n - 2; i >= 0; --i) {
    int diff = input[i] - input[i + 1];
    if (diff > m) {
      input[i + 1] = input[i] - m;
    } else if (diff < -m) {
      input[i] = input[i + 1] - m;
    }
  }

  for (const int n : input)
    fout << n << " ";

  fout << "\n";

  return 0;
}