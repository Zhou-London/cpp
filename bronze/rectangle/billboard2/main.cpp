
#include <algorithm>
#include <fstream>
struct Rect {
  int x1, y1, x2, y2;

  void read(std::ifstream &fin) { fin >> x1 >> y1 >> x2 >> y2; }
};

int main() {
  std::ifstream fin("billboard.in");
  std::ofstream fout("billboard.out");

  Rect ad, board;

  ad.read(fin);
  board.read(fin);

  

  return 0;
}