
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int main() {

  // std::ifstream fin("photoshoot.in");
  // std::ofstream fout("photoshoot.out");

  auto& fin = std::cin;
  auto& fout = std::cout;

  int N;
  fin >> N;

  std::string str;
  fin >> str;

  int reverse = 0;

  // * For each odd index
  // * Search from right to left
  for (int i = N - 2; i >= 0; i -= 2) {
    std::string pair = str.substr(i, 2);

    if (pair == "GH" && reverse % 2 == 0) {
      ++reverse;
    } else if (pair == "HG" && reverse % 2 != 0) {
      ++reverse;
    }
  }

  fout << reverse << "\n";

  return 0;
}