*This activity has been created as part of the 42 curriculum by lnaamneh, rajlouni.*

## Description
# Push_Swap
Push_Swap is an algorithmic project that challenges us to sort data on a stack, using a limited set of instructions, with the lowest possible number of actions. We are provided with two stacks (`a` and `b`). Stack `a` contains a random list of un-duplicated integers, and stack `b` is empty. 

The goal is to sort the numbers in stack `a` in ascending order using specific push, swap, and rotate operations. To achieve the best time complexity and operation count, this project implements multiple sorting strategies (O(n^2), O(n * sqrt(n)), and O(n log n)) and features an **Adaptive Algorithm** that calculates a "disorder" metric at runtime to dynamically select the most efficient sorting method. 

It also includes a built-in benchmarking tool to track operation counts, memory usage, and sorting efficiency.

---

## Instructions

### Compilation
The project includes a `Makefile`. To compile the program, run:

    make

This will generate the `push_swap` executable. Other available rules: `clean`, `fclean`, and `re`.

### Execution & Usage
Run the program by passing a list of integers as arguments. Strategy flags can be passed to force a specific algorithm, or the `--bench` flag can be added to output performance metrics. 

Flags and integer arguments are fully interchangeable and can appear in any order:

**Default (Adaptive) Execution:**

    ./push_swap 42 15 8 99 2

**Forcing a Specific Algorithm:**

    ./push_swap --simple 5 4 3 2 1
    ./push_swap --medium 10 9 8 7 6 5 4 3 2 1
    ./push_swap --complex 42 11 8 99 2 -3

**Benchmark Mode:**
Displays the measured disorder, chosen strategy, and a breakdown of all operations.

    ./push_swap --bench --adaptive 42 11 8 99 2 -3

**Interchangeable Arguments & Flags:**
Flags can be placed before, between, or after numeric values:

    ./push_swap 42 11 --bench 8 99 --complex 2 -3

---

## Algorithms: Explanation & Justification

We implemented three distinct sorting strategies and an adaptive router. Before sorting, the program calculates a **Disorder Metric** (between 0 and 1) by counting the number of "mistakes" or inversions (pairs where `a[i] > a[j]`) and dividing by the total possible pairs.

### 1. Simple Algorithm: Selection Sort (O(n^2))
**Trigger:** `--simple` flag or Disorder < 0.2.
**Explanation:** For small or nearly sorted stacks, complex partition logic just adds useless moves. This algorithm scans stack A for the lowest value, shifts it to the top using the shortest rotation (`ra` or `rra`), and pushes it to stack B (`pb`). Once stack A is empty, it drops everything back onto stack A (`pa`).
**Justification:** Fast and direct for inputs under 10–20 numbers. The O(n^2) cost is trivial at tiny sizes, and total operations stay minimal.

    [ Selection Sort Flow ]
    Stack A: [4, 1, 3, 2] -> Find Min (1) -> Rotate & pb -> Stack B: [1]
    Stack A: [4, 3, 2]    -> Find Min (2) -> Rotate & pb -> Stack B: [2, 1]
    ... finally pa all back to Stack A.

### 2. Medium Algorithm: Chunk Sort (O(n * sqrt(n)))
**Trigger:** `--medium` flag or 0.2 <= Disorder < 0.5.
**Explanation:** The list is divided into chunks (roughly sqrt(n) chunks). We scan stack A and push values belonging to the active chunk into stack B. If a pushed number lands in the lower half of that chunk, we run `rb` to move it to the bottom of stack B, rough-sorting on the fly. Once stack A is cleared, elements are pulled back into stack A by extracting the maximums.
**Justification:** Meets the O(n * sqrt(n)) requirement cleanly. Breaking values into chunks avoids making full-stack loops over and over like a selection sort would, making it solid for stacks around 100 numbers.

### 3. Complex Algorithm: Radix Sort (O(n log n))
**Trigger:** `--complex` flag or Disorder >= 0.5.
**Explanation:** Values are normalized into sequential indices (0 to N - 1). We sort through the numbers bit by bit in binary, starting from the least significant bit (LSB) up to the most significant bit. If the evaluated bit is `0`, we push to stack B (`pb`); if it's `1`, we rotate stack A (`ra`). Once all elements have been checked for that bit, stack B is emptied back into stack A.
**Justification:** Base-2 Radix Sort gives consistent O(n log n) scaling. It handles large datasets (like 500 numbers) reliably without hitting worst-case spikes or blowing the operation count.

    [ Binary Radix Sort Flow (Bit 0) ]
    Index: 3 (011) -> Bit is 1 -> ra
    Index: 2 (010) -> Bit is 0 -> pb
    Index: 1 (001) -> Bit is 1 -> ra
    Index: 0 (000) -> Bit is 0 -> pb

### 4. Adaptive Router
**Justification:** Instead of locking into one sorting method, the router checks stack disorder upfront. If the stack is a mess (e.g., 80% disorder), it fires Radix Sort. If the stack is mostly in place (e.g., 0.15 disorder), it skips the full bitwise passes and runs Selection Sort instead.

**Rationale for Thresholds & Internal Techniques:** 
- **Low Disorder (< 0.2):** When the stack is roughly 80% sorted or better, running heavy partitioning is a waste. We use **Selection Sort**. Grabbing the few misplaced numbers takes fewer moves overall.

- **Medium Disorder (0.2 to < 0.5):** The stack is moderately mixed up. We use **Chunk Sort**. Splitting values into sqrt(n) ranges hits a solid middle ground, keeping rotations low without committing to strict bit passes.

- **High Disorder (>= 0.5):** The stack is scrambled. We use **Base-2 Radix Sort** to guarantee steady performance across completely randomized or reverse-sorted inputs.

**Complexity Argument (Time & Space):**
- **Time Complexity:** Measured strictly in emitted `push_swap` instructions. Selection Sort is bounded by O(n^2) because it repeatedly searches the whole stack for minimum values. Chunk Sort runs in O(n * sqrt(n)) by processing sqrt(n) buckets. Radix Sort runs in O(n log n), bounded by the bit width required to represent N elements.

- **Space Complexity:** All routines sort in-place using stack A and stack B. The only allocated memory goes to the linked list nodes and the `t_bench` tracking struct. Total auxiliary space complexity is O(n).

---

## Team Contributions

This project was a collaborative effort by **lnaamneh** and **rajlouni**. 

**Shared Work:**
- **Core Data Structures:** Jointly developed the `t_stack` architecture and linked-list logic.
- **Operations:** Both implemented and debugged the Push_Swap instruction set (push, swap, rotate, reverse rotate).
- **Algorithm Utilities:** Shared development of helper functions (finding min/max, indexing).
- **Infrastructure:** Co-authored the `Makefile` and `push_swap.h` header files.

**Individual Focus - rajlouni:**
- **Parsing & Validation:** Handled `argc/argv` extraction, robust integer validation, and duplicate checking.
- **Error Handling & Memory:** Ensured Valgrind compliance and safe memory freeing (`ft_error_exit`).
- **Benchmarking System:** Designed the `t_bench` structure and print logic to track total operations and disorder statistics.
- **Complex Algorithm:** Researched and implemented the Base-2 **Radix Sort** (O(n log n)).

**Individual Focus - lnaamneh:**
- **Operations:** Handled the main engine for the operations: (push, swap, rotate, reverse rotate).
- **Simple Algorithm:** Implemented the optimized **Selection Sort** (O(n^2)).
- **Medium Algorithm:** Designed and implemented the **Chunk Sort** logic (O(n * sqrt(n))).
- **Adaptive Router:** Handled the overarching router logic that selects algorithms based on the calculated disorder thresholds.

---

## Resources

**Resources:**
- [VisuAlgo - Sorting](https://visualgo.net/en/sorting) - Reference for visualizing sorting behaviors and operation counts.
- [ISO/IEC 9899:1999 (C99) Standard](https://www.iso.org/standard/29242.html) - C language specification.

**AI Usage:**
- Used AI to brainstorm algorithmic trade-offs across stack architectures.
- Used AI to write Bash test scripts and generate randomized test suites with edge cases (duplicates, sorted sequences, INT_MIN/INT_MAX bounds, and random flags).

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
