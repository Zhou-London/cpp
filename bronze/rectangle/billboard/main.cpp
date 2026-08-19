
#include <algorithm>
#include <fstream>
struct Rect {
  int x1, y1, x2, y2;

  void read(std::ifstream &fin) { fin >> x1 >> y1 >> x2 >> y2; };
  int area() { return (x2 - x1) * (y2 - y1); }
};

int main() {
  std::ifstream fin("billboard.in");
  std::ofstream fout("billboard.out");

  Rect a, b, t;
  a.read(fin);
  b.read(fin);
  t.read(fin);

  auto intersect = [&](const Rect &a, const Rect &b) {
    int x = std::min(a.x2, b.x2) - std::max(a.x1, b.x1);
    x = x < 0 ? 0 : x;

    int y = std::min(a.y2, b.y2) - std::max(a.y1, b.y1);
    y = y < 0 ? 0 : y;

    return x * y;
  };

  int res = a.area() + b.area() - intersect(a, t) - intersect(b, t);
  fout << res << "\n";

  return 0;
}