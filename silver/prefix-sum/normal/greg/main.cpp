
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  // freopen("greg.in", "r", stdin);
  // freopen("greg.out", "w", stdout);

  struct Operation {
    int l;
    int r;
    long long c;
  };

  int n, m, k;
  std::cin >> n >> m >> k;
  
  // * Build diff array for original array
  std::vector<long long> vec(n + 2);
  for (int i = 1; i <= n; ++i) {
    std::cin >> vec[i];
  }

  std::vector<long long> diff(n + 2);
  for (int i = 1; i <= n; ++i) {
    diff[i] = vec[i] - vec[i - 1];
  }

  std::vector<Operation> ops(m);
  for (int i = 0; i < m; ++i) {
    int l, r, c;
    std::cin >> l >> r >> c;

    ops[i] = {l, r, c};
  }

  // * Build diff array for operation executions
  std::vector<long long> execs(m + 2); // op idx -> count
  for (int i = 0; i < k; ++i) {
    int l, r;
    std::cin >> l >> r;

    execs[l] += 1;
    execs[r + 1] -= 1;
  }

  // Revert exec to get execution times for each operation of index i
  for (int i = 1; i <= m; ++i) {
    execs[i] += execs[i - 1];
  }

  // Apply changes
  for (int i = 1; i <= m; ++i) {
    const auto& op = ops[i - 1]; // since ops is 0-indexed
    int op_count = execs[i];

    diff[op.l] += op.c * op_count;
    diff[op.r + 1] -= op.c * op_count;
  }

  // Revert diff to get final array
  for (int i = 1; i <= n; ++i) {
    diff[i] += diff[i - 1];

    std::cout << diff[i] << " ";
  }

  std::cout << "\n";
}