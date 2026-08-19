

#include <algorithm>
#include <fstream>
#include <vector>
int main() {
  std::ifstream fin("mixmilk.in");
  std::ofstream fout("mixmilk.out");

  std::vector<int> caps(3);
  std::vector<int> milk_of(3);

  fin >> caps[0] >> milk_of[0] >> caps[1] >> milk_of[1] >> caps[2] >>
      milk_of[2];

  for (int i = 0; i < 100; ++i) {
    int from = i % 3;
    int to = (i + 1) % 3;

    int amount = std::min(milk_of[from], caps[to] - milk_of[to]);

    milk_of[to] += amount;
    milk_of[from] -= amount;
  }

  fout << milk_of[0] << "\n" << milk_of[1] << "\n" << milk_of[2] << "\n";

  return 0;
}