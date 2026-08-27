

// * https://cses.fi/problemset/task/1164
// ? Priority Queue, Sorting, Greedy

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);

  int n;
  std::cin >> n;

  struct Cust {
    int a;
    int b;
    int idx;
  };

  std::vector<Cust> custs(n);
  std::vector<int> rooms(n); // cust.idx -> the room taken
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;

    custs[i] = {a, b, i};
  }

  std::sort(custs.begin(), custs.end(),
            [](const Cust &a, const Cust &b) { return a.a < b.a; });

  auto cmp = [](const Cust &a, const Cust &b) { return a.b > b.b; };
  std::priority_queue<Cust, std::vector<Cust>, decltype(cmp)> pq(cmp);

  int total_rooms = 0;

  for (int i = 0; i < n; ++i) {
    auto &c = custs[i];

    if (!pq.empty() && pq.top().b < c.a) {
      rooms[c.idx] = rooms[pq.top().idx];
      pq.pop();
      pq.push(c);
    } else {
      ++total_rooms;
      rooms[c.idx] = total_rooms;
      pq.push(c);
    }
  }

  std::cout << total_rooms << "\n";

  for (int i = 0; i < n; ++i) {
    std::cout << rooms[i] << " ";
  }

  return 0;
}