<img src="https://capsule-render.vercel.app/api?type=waving&height=400&text=CPP&fontAlign=80&fontAlignY=40&color=gradient" />

<p align="center">
  <img alt="C++17" src="https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white" />
  <img alt="Problems solved: 77" src="https://img.shields.io/badge/problems-77-4c1" />
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
silver/     USACO Silver topics: binary search, prefix sums, two pointers, sorting
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

Inside the body, `// !` marks the trap that a first attempt falls into — an
overflow that needs `long long`, a bound that is `< R` rather than `<= R`, a
container that is already sized. These are the notes worth rereading before a
contest.

A problem whose reasoning takes more than a comment carries a `sol.md` beside
`main.cpp`. The write-up derives the solution: what the problem turns into,
why the counting has no gaps and no repeats, and where the formula comes from.
These notes are written in Chinese.

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
| [`sorting`](silver/sorting) | 6 | Sort or compress the coordinates first, then sweep the order |

## Releases

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
