
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
int main() {
  auto &fin = std::cin;
  auto &fout = std::cout;

  long long N, K;
  fin >> N >> K;

  std::vector<long long> days(N);
  for (long long i = 0; i < N; ++i) {
    fin >> days[i];
  }

  long long cost = 1 + K;
  long long new_sub = 1 + K;
  auto extend = [&](long long next) { return days[next] - days[next - 1]; };

  for (long long i = 1; i < N; ++i) {
    cost = std::min(cost + new_sub, cost + extend(i));
  }

  fout << cost << "\n";
}