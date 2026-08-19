
#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>
int main() {
  // std::ifstream fin("aircow.in");
  // std::ofstream fout("aircow.out");

  auto &fin = std::cin;
  auto &fout = std::cout;

  int N, M;
  fin >> N >> M;

  struct Cow {
    int s;
    int t;
    int c;
  };

  struct AirCond {
    int a;
    int b;
    int p;
    int m;
  };

  std::vector<Cow> cows(N);
  std::vector<AirCond> airs(M);

  for (int i = 0; i < N; ++i) {
    Cow c;

    fin >> c.s;
    fin >> c.t;
    fin >> c.c;

    cows[i] = c;
  }

  for (int i = 0; i < M; ++i) {
    AirCond a;

    fin >> a.a;
    fin >> a.b;
    fin >> a.p;
    fin >> a.m;

    airs[i] = a;
  }

  std::vector<AirCond> path;
  int min_cost = INT_MAX;

  auto search = [&](auto &&self, int idx) -> void {
    if (idx == M) {
      int available = true;

      // Record cooling condition
      int cost = 0;
      std::vector<int> stall_cooling(101, 0);
      for (const auto &air : path) {
        for (int i = air.a; i <= air.b; ++i) {
          stall_cooling[i] += air.p;
        }

        cost += air.m;
      }

      // Check if meets requirements
      for (const auto &cow : cows) {
        for (int i = cow.s; i <= cow.t; ++i) {
          if (stall_cooling[i] < cow.c) {
            available = false;
            break;
          }
        }

        if (!available)
          break;
      }

      // Update
      if (available) {
        min_cost = std::min(min_cost, cost);
      }

      return;
    }

    self(self, idx + 1);
    path.push_back(airs[idx]);
    self(self, idx + 1);
    path.pop_back();
  };

  search(search, 0);
  fout << min_cost << "\n";

  return 0;
}