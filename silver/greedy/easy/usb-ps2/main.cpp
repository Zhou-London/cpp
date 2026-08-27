

// * https://codeforces.com/contest/762/problem/B
// ? Greedy

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
int main() {
  //   freopen("file.in", "r", stdin);
  //   freopen("file.out", "w", stdout);

  int a, b, c;
  std::cin >> a >> b >> c;

  int m;
  std::cin >> m;

  std::vector<int> usb;
  std::vector<int> ps2;

  for (int i = 0; i < m; ++i) {
    int num;
    std::string str;

    std::cin >> num >> str;

    if (str == "USB")
      usb.push_back(num);

    if (str == "PS/2")
      ps2.push_back(num);
  }

  std::sort(usb.begin(), usb.end());
  std::sort(ps2.begin(), ps2.end());

  long long equipped = 0;
  long long cost = 0;

  int l = 0; // ! Init
  int r = 0;

  long long usb_count = std::min<long long>(usb.size(), a);
  equipped += usb_count;
  for (int i = 0; i < usb_count; ++i) {
    cost += usb[i];
    l = i + 1;
  }

  long long ps2_count = std::min<long long>(ps2.size(), b);
  equipped += ps2_count;
  for (int i = 0; i < ps2_count; ++i) {
    cost += ps2[i];
    r = i + 1;
  }

  for (int i = 0; i < c; ++i) {
    if (l < usb.size() && r < ps2.size()) {
      if (usb[l] <= ps2[r]) {
        ++equipped;
        cost += usb[l];
        ++l;
      } else {
        ++equipped;
        cost += ps2[r];
        ++r;
      }
    } else if (l < usb.size()) {
      ++equipped;
      cost += usb[l];
      ++l;
    } else if (r < ps2.size()) {
      ++equipped;
      cost += ps2[r];
      ++r;
    } else {
      break;
    }
  }

  std::cout << equipped << " " << cost << "\n";
  return 0;
}