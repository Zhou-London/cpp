
#include <fstream>
#include <string>
int main() {
  std::ifstream fin("breedflip.in");
  std::ofstream fout("breedflip.out");

  int N;
  fin >> N;

  std::string A;
  std::string B;

  fin >> A;
  fin >> B;

  int variant = 0;

  for (int i = 0; i < N; ++i) {
    if (A[i] != B[i])
      ++variant;

    while (A[i] != B[i] && i < N) {
      ++i;
    }
  }

  fout << variant << "\n";
}