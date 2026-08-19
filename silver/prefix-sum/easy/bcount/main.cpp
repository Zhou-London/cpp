
#include <fstream>
#include <iostream>
#include <vector>
int main() {
  std::ifstream fin("bcount.in");
  std::ofstream fout("bcount.out");

  int N, Q;
  fin >> N >> Q;

  std::vector<int> psum_1(N + 1, 0);
  std::vector<int> psum_2(N + 1, 0);
  std::vector<int> psum_3(N + 1, 0);

  for (int i = 0; i < N; ++i) {
    int idx = i + 1;
    int n;
    fin >> n;

    psum_1[idx] = psum_1[i];
    psum_2[idx] = psum_2[i];
    psum_3[idx] = psum_3[i];

    // ! Break
    switch (n) {
    case 1: {
      ++psum_1[idx];
      break;
    }
    case 2: {
      ++psum_2[idx];
      break;
    }
    case 3: {
      ++psum_3[idx];
      break;
    }
    }
  }

  for (int i = 0; i < Q; ++i) {
    int a, b;
    fin >> a >> b;

    fout << psum_1[b] - psum_1[a - 1] << " " << psum_2[b] - psum_2[a - 1]
              << " " << psum_3[b] - psum_3[a - 1] << "\n";
  }

  return 0;
}