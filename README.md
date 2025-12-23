# Advent of Code 2025

My solutions for [Advent of Code 2025](https://adventofcode.com/2025) puzzles, written in C++.

## Progress

| Day | Part 1 | Part 2 |
|-----|--------|--------|
| 1   | ⭐     | ⭐     |
| 2   | ⭐     | ⭐     |
| 3   | ⭐     | ⭐     |
| 4   | ⭐     | ⭐     |

## Solutions

<details>
<summary>🎄 Day 1: Secret Entrance</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Tracks a circular position (0-99) based on left/right movements, counting how many times position 0 is reached. |
| ⭐⭐ | Counts every time the circular position crosses 0 during rotations, not just when it lands exactly on 0. |

</details>

<details>
<summary>🎄 Day 2: Gift Shop</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Finds mirror IDs (numbers that read the same when split in half, like `1212`) within given ranges and sums them. |
| ⭐⭐ | Extends Part 1 to find all repeating pattern numbers where a prefix repeats to form the entire number (ex: `123123`, `7777`) and sums them. |

</details>

<details>
<summary>🎄 Day 3: Max Voltage</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Finds the max 2 digit voltage by picking the largest digit and the largest remaining digit after it from each line. |
| ⭐⭐ | Extends to 12 digits: greedily selects the largest available digit at each position while making sure enough digits are left for the rest. |

</details>

<details>
<summary>🎄 Day 4: Printing Department</summary>

| Part | Description |
|:----:|-------------|
| ⭐ | Counts the number of filled entries that have fewer than 4 neighboring filled entries. |
| ⭐⭐ |  Continues removing cells with fewer than than 4 neighbors until stability is reached, counting the total removed. |

</details>

