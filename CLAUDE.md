# CLAUDE.md

Guidance for Claude Code when working in this repository.

## What this is

`cpp` — competitive programming solutions, one directory per problem, from
USACO, CSES, Codeforces, and CodeChef. See [README.md](README.md).

Nothing here is a library. No file includes another file in the repository,
there is no build system, and no header is shared. A problem directory is the
unit of work: one `main.cpp`, the sample input, the expected output, and
sometimes a `sol.md`.

## Layout

```
bronze/<topic>/<difficulty>/<problem>/    USACO Bronze
silver/<topic>/<difficulty>/<problem>/    USACO Silver
```

Topics are named after the technique they drill, not after the problems:
`binary-search`, `prefix-sum`, `two-pointer`, `coor-compress`, `simulation`,
`greedy`, `complete-search`. Difficulty is `easy`, `normal`, or `hard`. A new
problem goes under the technique that solves it.

## Building and running

```bash
cd silver/coor-compress/rental
g++ -std=c++17 -O2 main.cpp -o main
./main
```

The compiled `main` is gitignored. Build inside the problem directory, because
a USACO solution opens its input file by a relative path.

## Input and output

The judge decides which one a solution uses.

- **USACO** grades from files named after the problem. Open them with
  `freopen("<problem>.in", "r", stdin)` and
  `freopen("<problem>.out", "w", stdout)` as the first two statements of
  `main`.
- **CSES, Codeforces, CodeChef** read standard input. Keep the two `freopen`
  lines commented out, and name the local sample files `file.in` and
  `file.out`.

Read with `std::cin` and write with `std::cout`. The Bronze solutions open the
files directly, with `std::ifstream fin` and `std::ofstream fout`; leave them
as they are, and write new solutions with `freopen`.

## Solution header

Every new solution opens with two comment lines:

```cpp
// * https://usaco.org/index.php?page=viewproblem2&cpid=787
// ? Prefix sum, Suffix sum, 2 Pointer
```

`// *` links the problem statement. `// ?` lists the techniques, comma
separated, so the directory can be searched by technique.

Inside the body, `// !` marks a trap: an intermediate value that overflows
`int`, an index bound that is easy to write off by one, a container that is
already sized. Mark the trap where the code handles it. Never explain what the
line does — the code says that.

Follow [humandoc](https://github.com/Zhou-London/n-skills) for every comment.
Write the present state, put the fact first, keep one clause per sentence.

## sol.md

A problem whose reasoning does not fit in comments gets a `sol.md` beside
`main.cpp`. It derives the solution: the transformation, why the counting
covers every case exactly once, and the final formula. These are written in
Chinese; match the language of the file being edited.

## Style

- C++17, standard library only. No `bits/stdc++.h`, no `using namespace std`.
  Qualify names as `std::sort`, `std::vector`.
- Two-space indent, opening brace on the same line — clang-format's LLVM
  style, which is the default.
- Use `long long` for any sum of products, any prefix sum, and any coordinate
  that the statement lets exceed 2·10⁹.
- Name variables after the statement: `N`, `M`, `R` for the input sizes the
  problem names, plain words for the rest.

## Commits

One day of solving per commit. Subject names what was added, imperative, for
example `silver/coor-compress: add rental and rest-customers`. Compiled
binaries and `.DS_Store` stay untracked.
