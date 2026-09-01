<img src="https://capsule-render.vercel.app/api?type=waving&height=400&text=CPP&fontAlign=80&fontAlignY=40&color=gradient" />

<p align="center">
  <img alt="C++17" src="https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white" />
  <img alt="Problems solved: 101" src="https://img.shields.io/badge/problems-101-4c1" />
  <img alt="USACO" src="https://img.shields.io/badge/USACO-bronze%20%7C%20silver-1f6feb" />
  <img alt="CSES" src="https://img.shields.io/badge/judge-CSES-6f42c1" />
  <img alt="Codeforces" src="https://img.shields.io/badge/judge-Codeforces-1F8ACB" />
  <img alt="Build: single translation unit" src="https://img.shields.io/badge/build-one%20file-lightgrey" />
</p>

**Competitive Programming Plus** — solutions to USACO, CSES, Codeforces, and
CodeChef problems, one directory per problem.

Each problem is a self-contained folder: one `main.cpp`, and the sample input
and output the judge gives. Nothing is shared between folders. A solution
compiles on its own, runs on its own, and can be read on its own.

## Layout

```
bronze/     USACO Bronze topics: simulation, greedy, complete search, casework, sorting, maps, rectangles, graphs
silver/     USACO Silver topics: binary search, prefix sums, two pointers, sorting, greedy, priority queues, graphs
```

A problem lives in its own directory under a topic. Older topics group the
problems by difficulty first — `easy`, `normal`, or `hard` — and newer topics
hold the problem directories directly:

```
silver/sorting/rental/           a topic that holds problems directly
    main.cpp        the solution
    rental.in       the sample input
    rental.out      the expected output

silver/binary-search/easy/angry/ a topic that groups by difficulty first
```

## Running a solution

Compile the single file and run it in its own directory:

```bash
cd silver/sorting/rental
g++ -std=c++17 -O2 main.cpp -o main
./main
```

The compiled `main` is gitignored, so a build leaves the working tree clean.

## Input and output

USACO grades from files named after the problem. A USACO solution redirects
the standard streams onto those files in its first two lines:

```cpp
freopen("file.in", "r", stdin);
freopen("file.out", "w", stdout);
```

CSES, Codeforces, and CodeChef read standard input and write standard output,
so a solution for those judges keeps the two calls commented out and names its
local samples `file.in` and `file.out`. Running such a solution locally means
typing the sample input, or piping it in:

```bash
./main < file.in
```

The Bronze solutions open the two files directly instead, with
`std::ifstream fin` and `std::ofstream fout`. Both styles reach the same
grader; Silver moved to `freopen` so that `std::cin` and `std::cout` work
unchanged on every judge.

## Solution conventions

Every solution opens with two comment lines that say where the problem comes
from and what solves it:

```cpp
// * https://usaco.org/index.php?page=viewproblem2&cpid=787
// ? Prefix sum, Suffix sum, 2 Pointer
```

The `// *` line links the problem statement. The `// ?` line lists the
techniques, so a topic directory can be searched by technique rather than by
problem name.

A third header line carries the judge's difficulty rating, as a bare number:

```cpp
// ! 1900
```

The rating places the problem on the scale its own judge publishes. A problem
whose judge publishes no rating leaves the line out.

Inside the body, `// !` marks the trap that a first attempt falls into — an
overflow that needs `long long`, a bound that is `< R` rather than `<= R`, a
pointer that starts uninitialized. These are the notes worth rereading before
a contest.

A problem whose reasoning takes more than a comment carries a `sol.md` beside
`main.cpp`. The write-up derives the solution: what the problem turns into,
why the counting has no gaps and no repeats, and where the formula comes from.
Some write-ups instead walk one worked example through the whole argument, and
close with a question to answer before the next attempt. These notes are
written in Chinese.

## Topics

### Bronze

| Topic | Problems | What it drills |
|---|---|---|
| [`simulation`](bronze/simulation) | 12 | Follow the statement step by step, exactly as written |
| [`greedy`](bronze/greedy) | 7 | Prove that the locally best choice stays best |
| [`complete-search-recursion`](bronze/complete-search-recursion) | 5 | Enumerate permutations and subsets by recursion |
| [`complete-search`](bronze/complete-search) | 4 | Enumerate every candidate when the input is small |
| [`rectangle`](bronze/rectangle) | 3 | Overlap, union, and area of axis-aligned rectangles |
| [`casework`](bronze/casework) | 2 | Split the input into cases that each have one answer |
| [`sorting`](bronze/sorting) | 2 | Sort first, then read the answer off the order |
| [`maps`](bronze/maps) | 2 | Count and look up with `std::map` and `std::set` |
| [`graph`](bronze/graph) | 1 | Walk a small graph by flood fill |

### Silver

| Topic | Problems | What it drills |
|---|---|---|
| [`binary-search`](silver/binary-search) | 14 | Binary search on the answer, and on a sorted array |
| [`prefix-sum`](silver/prefix-sum) | 11 | Range sums in O(1), 1D and 2D, plus difference arrays |
| [`two-pointer`](silver/two-pointer) | 8 | Slide a window over a sorted array in O(n) |
| [`sorting`](silver/sorting) | 8 | Sort or compress the coordinates first, then sweep the order |
| [`greedy`](silver/greedy) | 12 | Take the best choice at each step, after sorting |
| [`priority-queue`](silver/priority-queue) | 5 | Keep the open candidates in a heap and pop the best one |
| [`graph`](silver/graph) | 5 | Walk the graph by BFS: components, two-coloring, reachability |

## Releases

### 2026-08-31

Graphs opened as a Silver topic, and priority queues grew past interval
scheduling.

- **`silver/graph` holds five solved problems**, all of them solved by breadth-first
  search over an adjacency list. The topic groups them under `easy`.
- **`silver/graph/easy/building-roads`** — [CSES Building Roads](https://cses.fi/problemset/task/1666).
  Runs one BFS per unvisited city and keeps the first city of each component.
  Joining every later component to the first one costs `components - 1` roads,
  which is the minimum.
- **`silver/graph/easy/building-teams`** — [CSES Building Teams](https://cses.fi/problemset/task/1668).
  Colors the graph with two colors during BFS, giving each neighbour the other
  color. An edge between two pupils of one color prints `IMPOSSIBLE` and stops.
- **`silver/graph/easy/closing`** — [USACO Closing the Farm](https://usaco.org/index.php?page=viewproblem2&cpid=644).
  Counts the components among the open barns before each closing, and answers
  `YES` when exactly one component remains. The count is a fresh BFS sweep per
  step, which the Silver input size allows.
- **`silver/graph/easy/fenceplan`** — [USACO Fence Planning](https://usaco.org/index.php?page=viewproblem2&cpid=944).
  Takes the bounding box of each component during BFS and returns the smallest
  perimeter. The perimeter needs `long long`.
- **`silver/graph/easy/moocast`** — [USACO Moocast](https://usaco.org/index.php?page=viewproblem2&cpid=668).
  Runs a BFS from every cow and keeps the largest count reached. The edges are
  directed, because one cow reaches another when its own radius covers the
  distance, so each BFS starts from a fresh `visited` array. Distances are
  compared squared, which keeps the arithmetic in integers.
- **`silver/graph/easy/birthday`** — [Kattis Birthday](https://open.kattis.com/problems/birthday).
  Reads the test cases and builds the adjacency list. The solution stops there;
  the component test is still to write.
- **`silver/priority-queue/helpcross`** — [USACO Help Cross](https://usaco.org/index.php?page=viewproblem2&cpid=714).
  Sorts the chickens by time and the cows by interval start, then pushes every
  interval that has already opened into a heap keyed on end time. Each chicken
  takes the open interval that ends first, and intervals that already closed
  are dropped on the way.
- **`silver/priority-queue/packing-regulation`** — [AtCoder ABC 214 E](https://atcoder.jp/contests/abc214/tasks/abc214_e).
  Sweeps the box indices upward and holds the balls whose range has opened in a
  heap keyed on the last index they accept. Each index takes the ball with the
  tightest deadline; a ball whose deadline has passed prints `No`.
- **`silver/priority-queue/william-robot`** — [Codeforces Gym 104002 E](https://codeforces.com/gym/104002/problem/E).
  Turns a fixed-strategy opponent into one prefix constraint: among the first
  `k` numbers, at most `⌈k/2⌉` can be kept. A min-heap takes every number and
  pops the smallest whenever the quota breaks. The `sol.md` derives the
  constraint by counting, and lists `(i + 2) / 2` as the precedence trap.
- **`silver/sorting/measurement`** — [USACO Milk Measurement](https://usaco.org/index.php?page=viewproblem2&cpid=763).
  Sorts the log entries by day and replays them, keeping each cow's amount in a
  hash map and every amount in a `std::multiset`. The leader is the largest
  amount in the multiset, and the display changes when a cow enters the top,
  leaves it, or joins a tie.
- **`silver/graph/easy/moocast` dropped `#include <endian.h>`.** The header
  ships with glibc only, so the build in the README failed on macOS.
- **`helpcross` and `birthday` filled their `// ?` line.** Both had an empty
  technique list, which leaves the directory unsearchable by technique.

### 2026-08-27

Priority queues opened as a Silver topic, and greedy grew a `normal` level for
the problems that need two strategies instead of one.

- **`silver/priority-queue` holds two problems.** Both sort the intervals by
  start time and keep the open ones in a heap, so the interval that ends first
  is always one pop away.
- **`silver/priority-queue/room-alloc`** — [CSES Room Allocation](https://cses.fi/problemset/task/1164).
  Sorts the customers by arrival and keeps the occupied rooms in a heap keyed
  on departure. A customer reuses the room that frees first when it is already
  free, and opens a new room otherwise. The number of rooms opened is the
  answer.
- **`silver/priority-queue/convention-2`** — [USACO Convention II](https://usaco.org/index.php?page=viewproblem2&cpid=859).
  Keeps the waiting cows in a heap keyed on seniority and serves the most
  senior one whenever the grass frees up. The `sol.md` rebuilds the driving
  loop around the moment the grass frees up, rather than the moment a cow
  arrives, so a cow arriving exactly then still joins the queue.
- **`silver/greedy/normal/ciel-duel`** — [Codeforces 321B](https://codeforces.com/contest/321/problem/B).
  Scores two strategies and takes the better one. The first attacks only the
  ATK cards and sums the damage. The second destroys every card Jiro holds and
  then sends the leftover cards straight at him, which only pays off when the
  cards run out exactly.
- **`silver/greedy/normal/yet-another-tour`** — [Codeforces 1783C](https://codeforces.com/contest/1783/problem/C).
  Sorts the opponents by cost and beats the cheapest ones the budget allows.
  The rank is then `n - k` or `n - k + 1`, so the solution tries one swap:
  drop the most expensive opponent bought and buy opponent `k + 1` instead.
  The `sol.md` derives the swap from a three-player example.
- **`silver/greedy/easy/cardgame`** — [USACO Cow Card Game](https://usaco.org/index.php?page=viewproblem2&cpid=573).
  Splits both hands in half and sorts each half so that Bessie meets Elsie's
  weak half with her strong cards. Two pointer walks then count the rounds
  Bessie wins.
- **`silver/greedy/easy/highcard`** — [USACO High Card Wins](https://usaco.org/index.php?page=viewproblem2&cpid=571).
  Sorts both hands ascending and walks them with two pointers. Bessie answers
  each of Elsie's cards with her cheapest card that still beats it.
- **`silver/greedy/easy/lemonade`** — [USACO Lemonade Line](https://usaco.org/index.php?page=viewproblem2&cpid=835).
  Sorts the patience values descending and counts how many cows still accept
  the queue length in front of them.
- **`silver/greedy/easy/usb-ps2`** initializes both pointers at zero. Reading
  an uninitialized pointer left the cost undefined on some inputs.
- **The header may carry a `// !` rating line**, a bare number on the judge's
  own scale. Six solutions carry one so far.

### 2026-08-25

Greedy opened as a Silver topic, and `sorting` gained its hardest problem.

- **`silver/greedy` holds seven problems**, all of them sorted first and then
  swept once. The topic groups them under `easy`.
- **`silver/greedy/easy/apartments`** — [CSES Apartments](https://cses.fi/problemset/task/1084).
  Sorts applicants and apartments, then walks both with two pointers. A pair
  matches when the apartment size falls within `k` of the wish.
- **`silver/greedy/easy/ferris-wheel`** — [CSES Ferris Wheel](https://cses.fi/problemset/task/1090).
  Sorts the weights and pairs the lightest child with the heaviest one that
  still fits. A child who fits beside a heavier partner also fits beside a
  lighter one, so the left pointer never moves alone.
- **`silver/greedy/easy/movie-festival`** — [CSES Movie Festival](https://cses.fi/problemset/task/1629).
  Sorts the movies by end time and takes each movie that starts after the
  current end. The earliest end leaves the most room for the rest.
- **`silver/greedy/easy/stick-lengths`** — [CSES Stick Lengths](https://cses.fi/problemset/task/1074).
  Sorts the sticks and cuts every one of them to the median. The total cost
  needs `long long`.
- **`silver/greedy/easy/tasks-deadlines`** — [CSES Tasks and Deadlines](https://cses.fi/problemset/task/1630).
  Sorts the tasks by duration ascending and runs them in that order. The
  shortest task first keeps the running clock lowest for everything after it.
- **`silver/greedy/easy/studying-algor`** — [Codeforces Gym 102951B](https://codeforces.com/gym/102951/problem/B).
  Sorts the durations ascending and counts how many fit inside the budget.
- **`silver/greedy/easy/usb-ps2`** — [Codeforces 762B](https://codeforces.com/contest/762/problem/B).
  Fills the USB-only and PS/2-only ports from the cheapest mice of each kind,
  then fills the shared ports by merging what is left of the two sorted lists.
- **`silver/sorting/lifeguards`** — [USACO Lifeguards](https://usaco.org/index.php?page=viewproblem2&cpid=786).
  Compresses the shift ends onto sorted unique indices and builds a difference
  array over them. One prefix sum gives the total covered time, a second one
  gives the time that a single lifeguard covers alone, and the answer drops the
  lifeguard whose alone-time is smallest.

### 2026-08-24

Coordinate compression grew into the wider `sorting` topic, and the repository
gained the documentation it never had.

- **`silver/coor-compress` became `silver/sorting`.** Every problem there
  sorts first and compresses second, so the topic now carries the name of the
  step that does the work. The problem directories moved unchanged.
- **`silver/sorting/rental`** — [USACO Rental Service](https://usaco.org/index.php?page=viewproblem2&cpid=787).
  Sorts cows, shops, and rents downward, builds a prefix sum over milk revenue
  with a two-pointer walk across shops, builds a suffix sum over rents, and
  takes the best split between the two. Revenue needs `long long`.
- **`silver/sorting/rest-customers`** — [CSES Restaurant Customers](https://cses.fi/problemset/task/1619).
  Compresses arrival and departure times onto sorted unique indices, adds +1
  and -1 into a difference array, and reads the maximum off the running sum.
- **`silver/sorting/mountains`** — [USACO Mountain View](https://usaco.org/index.php?page=viewproblem2&cpid=896).
  Turns each mountain into the interval `[x - y, x + y]`, sorts by left edge
  ascending and right edge descending, then counts the intervals whose right
  edge beats every earlier one. Those are the visible peaks.
- **`silver/sorting/covered-points-count`** — [Codeforces 1000C](https://codeforces.com/problemset/problem/1000/C).
  Compresses the interval ends onto sorted unique indices, adds +1 and -1 into
  a difference array, and sums the gap widths per coverage count. The right
  end is inclusive, so the -1 lands on `R + 1`.
- **`README.md` describes the repository**, listing every topic with its
  problem count, the build and run commands, the file naming the judges
  expect, and the meaning of the `// *`, `// ?`, and `// !` comment tags.
- **`CLAUDE.md`** records the same conventions for Claude Code, so a new
  solution lands in the right directory with the right header.
- **`.gitignore` covers macOS and build leftovers** — `.DS_Store`, `a.out`,
  object files, and debug bundles join the compiled `main`.

### 2026-08-21

Coordinate compression opened as a topic.

- **`rec-pasture`** counts the cow subsets a rectangle can enclose, by naming
  each subset with its leftmost and rightmost cow. **`static-range`** answers
  range queries after compressing the coordinates. `rec-pasture` carries a
  `sol.md` deriving its counting argument.

### 2026-08-20

Silver binary search reached the harder problems — `magic-ship`,
`meeting-place`, `multi-table`, `triptastic`, and a rewritten `mahmoud-ehab`.
Every one of them searches on the answer rather than on an array.

### 2026-08-19

The repository opened with the USACO Bronze topics — simulation, greedy,
complete search, casework, sorting, maps, rectangles, and graphs — together
with Silver prefix sums and two pointers. Silver binary search followed the
same day.
