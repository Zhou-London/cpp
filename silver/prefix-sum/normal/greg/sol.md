# 前缀和衍生：入门差分数组
差分数组（difference array）是建立在前缀和基础上的一种数学技巧，它计算并保存原数组相邻两个值的差值，然后通过O（1）叠加区间加减，最后对差分数组进行一次前缀和就能还原出进行区间加减后的数组。它常用于静态的区间变化问题。

## 数学原理
假设一个情景，给你多个范围[l,r]，对于一个范围，l到r之间的所有计数都+1。暴力算当然容易，O（n）在原始数组遍历区间做加法就可以，但是性能不够看。注意到一个关键观察，如果一个区间整体加加减减，那么这个区间内相邻两个值的差值还是不变的，好比[1,1,1,1,1]变成[1,2,2,2,1]，中间222之间的差值依旧是0，只有这个区间的头尾和相邻的差值变了。所以我们先写出这个数组变化前后的差分数组，计算公式为`d[i] = a[i] - a[i - 1]`，另外需要在头尾留出两个为0的哨兵节点（这里用\*标记）
[0*, 1, 0, 0, 0, 0, 0*] -> [0*, 1, 1, 0, 0, -1, 0*]
在继续讲解之前，你不妨尝试对这个差分数组做前缀和，如果前缀和结果等于原数组，那么就能证明这个差分数组是正确的。
观察到差分数组在前后的变化，我们的操作是在[2,4]（1-indexed）这个区间里对所有元素+1，反映到差分数组上变成了`diff[l] += 1`和`diff[r + 1] -= 1`（0-indexed），我们可以通过很多方式证明这个规律是成立的（prove by ac！）
由此，我们只需要在差分数组中对n个区间操作，每次做O（1）的变化，最后再O（n）前缀和还原，就能使用线性的复杂度完成区间操作。

## 局限性
差分数组是静态的，他只能解决“一系列操作后，最后的状态”这类问题，如果需要动态的解决问题，例如先进行操作1，看看状态，再操作2，看看状态，那么这个时候差分数组又会退化到O（n^2），要解决这个问题，只能考虑线段树或fenwick tree一类的树状数组。

## 例题
（CF 179 Div1 A）给定一个大小为`n`的原始数组，大小为`m`的操作定义数组，大小为`k`的操作执行数组。操作定义是对区间`[l,r]`的原始数组的元素加`c`，操作执行是对区间`[l,r]`的操作定义执行一次。需要你算出最后的数组。

## 思路
我对题目简化过后你应该很容易发现这道题目需要套两层差分，首先对操作执行差分，套用变化，再还原，获得每个操作被执行了多少次。然后再对原数组差分，然后对每个操作执行对应的操作次数，最后再还原数组，得到最终数组。我们使用`ops`数组存储所有的操作，再使用`execs`数组记录下标对应的操作的执行次数，然后对于每个操作`op`，在差分数组`diff`上，执行`diff[op.l] += op.c * execs`与`diff[op.r] += op.c * execs`。

## 祖训
前缀和的祖训依旧适用，凡是前缀和相关数组全都用`long long`，所以哪怕是差分也用`long long`，因为差分最后也要靠前缀和还原，这道题如果用32位int那么test 14就会因为溢出过不去了。

另外，头部的哨兵节点必须有，尾部的哨兵节点在这道题里可以去掉。

## 原创实现（C++）
AC
```cpp

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
```