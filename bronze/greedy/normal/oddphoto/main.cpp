
#include <fstream>
#include <iostream>
#include <vector>
int main() {

  //   std::ifstream fin("oddphoto.in");
  //   std::ofstream fout("oddphoto.out");

  auto &fin = std::cin;
  auto &fout = std::cout;

  int N;
  fin >> N;

  std::vector<int> cows(N);
  for (int i = 0; i < N; ++i)
    fin >> cows[i];

  int even_num = 0;
  int odd_num = 0;
  for (int n : cows) {
    if (n % 2 == 0)
      ++even_num;
    else
      ++odd_num;
  }

  int ans = 0;

  for (int i = N; i >= 0; --i) {
    // A: Number of even group
    // B: Number of odd group
    // R: odd_num - B

    int A = (i % 2 == 0) ? i / 2 : i / 2 + 1;
    int B = i / 2;

    // * R is even
    int R = odd_num - B;

    if (R % 2 != 0)
      continue;

    if (R < 0)
      continue;

    // * E + R / 2 >= A
    if (even_num + R / 2 < A)
      continue;

    ans = i;
    break;
  }

  fout << ans << "\n";

  return 0;
}