
// * https://codeforces.com/gym/102951/problem/D
// ? Psum & Diff array, Coord compression, Binary search

#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
//   freopen("file.in", "r", stdin);
//   freopen("file.out", "w", stdout);

  int N, Q;
  std::cin >> N >> Q;

  std::vector<std::array<long long, 3>> updates;
  std::vector<std::array<long long, 2>> queries;
  std::vector<long long> vertexs;

  for (int i = 0; i < N; ++i) {
    long long l, r, v;
    std::cin >> l >> r >> v;

    updates.push_back({l, r, v});

    vertexs.push_back(l);
    vertexs.push_back(r);
  }

  for (int i = 0; i < Q; ++i) {
    long long l, r;
    std::cin >> l >> r;

    queries.push_back({l, r});

    vertexs.push_back(l);
    vertexs.push_back(r);
  }

  std::sort(vertexs.begin(), vertexs.end());
  vertexs.erase(std::unique(vertexs.begin(), vertexs.end()),
                vertexs.end()); // ! Erase the unique

  auto idx = [&](int val) {
    return std::lower_bound(vertexs.begin(), vertexs.end(), val) -
           vertexs.begin();
  };

  // Build diff array
  int M = vertexs.size(); // ! Size after compressed
  std::vector<long long> diff(M + 1, 0);

  for (int i = 0; i < N; ++i) { // !
    const auto &update = updates[i];

    diff[idx(update[0])] += update[2]; // [l] += v
    diff[idx(update[1])] -= update[2]; // [r] -= v
  }

  // Restore the original array
  for (int i = 0; i + 1 < M; ++i) { // !
    diff[i + 1] += diff[i];
  }

  auto len = [&](int i) { return vertexs[i + 1] - vertexs[i]; };

  // Psum
  std::vector<long long> psum(M + 1, 0);
  for (int i = 0; i < M; ++i) {
    psum[i + 1] = psum[i] + diff[i] * len(i);
  }

  for (const auto &q : queries) {
    int r = idx(q[1]);
    int l = idx(q[0]);
    std::cout << psum[r] - psum[l] << "\n";
  }

  return 0;
}