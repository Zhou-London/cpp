
#include <cstdio>
#include <iostream>
#include <vector>
int main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<int> a(n);
  std::vector<int> b(m);

  auto func = [&](int J) {
    int sign = -1;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
      sign *= -1;
      sum += sign * (a[i] - b[i + J]);
    }
  };
}