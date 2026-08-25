

// * https://cses.fi/problemset/task/1090/
// ? Greedy, 2 Pointer (Clashing)

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int n, x;
  std::cin >> n >> x;

  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i)
    std::cin >> vec[i];

  std::sort(vec.begin(), vec.end());

  long long total = n;
  long long minus = 0;
  int l = 0;
  int r = n - 1;
  while (l < r) {
    if (vec[l] + vec[r] <= x) { // ! Never throw the left because if a bigger fits in the smaller must fit in as well
      ++l;
      --r;
      ++minus;
    } else {
      --r;
    }
  }

  std::cout << total - minus << "\n";
}