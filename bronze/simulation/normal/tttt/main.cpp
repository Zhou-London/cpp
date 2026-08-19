
#include <fstream>
#include <set>
#include <string>
#include <vector>
int main() {
  std::ifstream fin("tttt.in");
  std::ofstream fout("tttt.out");

  std::vector<std::string> rows(3);

  for (int i = 0; i < 3; ++i)
    fin >> rows[i];

  std::set<std::set<char>> indiv;
  std::set<std::set<char>> team;

  auto insert = [&](char a, char b, char c) {
    std::set<char> set;

    set.insert(a);
    set.insert(b);
    set.insert(c);

    if (set.size() == 1)
      indiv.insert(set);
    if (set.size() == 2)
      team.insert(set);
  };

  // Row
  for (int i = 0; i < 3; ++i) {
    insert(rows[i][0], rows[i][1], rows[i][2]);
  }

  // Col
  for (int i = 0; i < 3; ++i) {
    insert(rows[0][i], rows[1][i], rows[2][i]);
  }

  // Diagnol
  insert(rows[0][0], rows[1][1], rows[2][2]);
  insert(rows[2][0], rows[1][1], rows[0][2]);

  fout << indiv.size() << "\n" << team.size() << "\n";
}