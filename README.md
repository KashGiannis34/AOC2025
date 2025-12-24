# Advent of Code 2025

My solutions for [Advent of Code 2025](https://adventofcode.com/2025) puzzles, written in C++.

## Progress

| Day | Part 1 | Part 2 |
|-----|--------|--------|
| 1   | ⭐     | ⭐     |
| 2   | ⭐     | ⭐     |
| 3   | ⭐     | ⭐     |
| 4   | ⭐     | ⭐     |
| 5   | ⭐     | ⭐     |
| 6   | ⭐     | ⭐     |

## Solutions

<details>
<summary>🎄 Day 1: Secret Entrance</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Tracks a circular position (0-99) based on left/right movements, counting how many times position 0 is reached. I simulate the movement by updating a `currVal` variable modulo 100, incrementing a counter whenever `currVal` becomes 0. |
| ⭐⭐ | Counts every time the circular position crosses 0 during rotations, not just when it lands exactly on 0. I calculate the target position for each move and check if the path crosses the threshold (0 or 100), adding the number of full rotations and crossing events to the total count. |

</details>

<details>
<summary>🎄 Day 2: Gift Shop</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Finds mirror IDs (numbers that read the same when split in half, like `1212`) within given ranges and sums them. I iterate through numbers constructed by concatenating a prefix with itself, checking if they fall within the specified range and adding them to the sum. |
| ⭐⭐ | Extends Part 1 to find all repeating pattern numbers where a prefix repeats to form the entire number (ex: `123123`, `7777`) and sums them. I iterate through each number in the range and check divisors of its length to see if a substring repeats to form the original string. |

</details>

<details>
<summary>🎄 Day 3: Max Voltage</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Finds the max 2 digit voltage by picking the largest digit and the largest remaining digit after it from each line. I precompute suffix maximums to efficiently find the largest digit available after any given index, then iterate to find the optimal pair. |
| ⭐⭐ | Extends to 12 digits: greedily selects the largest available digit at each position while making sure enough digits are left for the rest. I use a greedy approach, selecting the largest possible digit for each position that still leaves enough remaining digits to complete the 12-digit number. |

</details>

<details>
<summary>🎄 Day 4: Printing Department</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Counts the number of filled entries that have fewer than 4 neighboring filled entries. I iterate through the grid, checking the 8 neighbors of each filled cell and counting those that satisfy the condition. |
| ⭐⭐ |  Continues removing cells with fewer than than 4 neighbors until stability is reached, counting the total removed. I use a `do-while` loop to repeatedly scan the grid and remove unstable cells, accumulating the count of removed cells until no more changes occur. |

</details>

<details>
<summary>🎄 Day 5: Cafeteria</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Counts how many specific IDs from a list fall within a given set of ranges. I sort the ranges and the IDs, then iterate through the IDs, advancing the range pointer to efficiently check for inclusion. |
| ⭐⭐ | Calculates the total number of unique integers covered by the union of the given ranges. I sort the ranges by start value and merge overlapping or adjacent intervals, summing the lengths of the merged intervals. |

</details>

<details>
<summary>🎄 Day 6: Trash Compactor</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Adds or multiplies the numbers in a given columns and sums up all of
the resulting values. I use input stream to find the numbers in each row,
store these values in a vector, and sum the results of all the problems. |
| ⭐⭐ | Completes the same problems, but the numbers are displayed vertically
instead of horizontally. I store all the lines of input as strings and iterate from left to right by column to determine each number. |

</details>