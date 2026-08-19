# Subsequences Summing to Sevens题解

## Ref
原题：https://usaco.org/index.php?page=viewproblem2&cpid=595

## 题干讲解
题目的意思很直接，给定一定长度的正整数数组，要求找到最长的**子序列**，使其总和为7的倍数。
这道题目需要用到的基本功还是比较多的，虽然难度被归类为easy，但掌握套路以后能复用的地方非常多。
首先注意到子序列和的问题，自然会想到用**前缀和**，前缀和通过一次O(n)构建后，算任意子序列的区间和都只需要O(1)。
```cpp
S(i, j) = P[j] - P[i - 1]
```
因此我们首先直接对输入预处理，处理成前缀和数组，原始的数组我们可以完全不关心。
随后问题就可以转化为，找出所有的j和i, s.t:
```cpp
P[j] - P[i - 1] mod 7 == 0
```
Recall我们先前讲过，你们离散数学里也学过的**同余**概念：
```cpp
// equivalent to
P[j] = P[i - 1] (mod 7)
```
由此我们推导出，想找出这样的j和i，只需要看哪两个位置除以7后的余数相同。
要解决这个问题，我们可以使用笨办法，对每个位置都往后扫描一遍，O(n^2)，基本没得玩。
所以继续用到另一个哈希技巧，我们只做一边扫描，对于每个位置，计算其除以7的余数，在哈希里找一找有没这个余数。
如果有这个余数，说明撞出了一对，算一下序列长度`j - i + 1`比较一下。
如果没这个余数，把余数和索引作为KV存入哈希表。
同时这里也有个贪心思想，因为我们知道序列长度越长越好，所以如果撞出了同样的余数，那么新的位置不用更新进去，**因为只要余数相同，旧的更小的位置就依然生效**，长度自然也更大。

## 代码细节
包含前缀和在内的求和题目，凡是存和，无脑使用`long long`，否则溢出到麻。
C++实现中这里可以用到工作中非常常用的`try emplace` + Pair绑定的技巧，不过由于17才支持所以竞赛中少见。

## 原创C++实现
已AC
```cpp
#include <algorithm>
#include <climits>
#include <fstream>
#include <unordered_map>
#include <vector>
int main() {
  std::ifstream fin("div7.in");
  std::ofstream fout("div7.out");

  int N;
  fin >> N;

  std::vector<long long> psum(N + 1, 0);
  for (int i = 0; i < N; ++i) {
    int n;
    fin >> n;

    psum[i + 1] = psum[i] + n;
  }

  std::unordered_map<long long, long long> map;

  // * (S[j] - S[i]) mod 7 == 0
  // * -> S[j] mod 7 == S[i] mod 7
  long long ans = LLONG_MIN;
  for (int i = 0; i <= N; ++i) {
    auto it = map.find(psum[i] % 7);
    if (it != map.end()) {
      long long len = i - it->second;
      ans = std::max(ans, len);
    } else {
      // * Greedy update the index
      map[psum[i] % 7] = i;
    }
  }

  fout << ans << "\n";
  return 0;
}
```