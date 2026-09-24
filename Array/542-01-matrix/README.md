# 542. 01 Matrix

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/01-matrix/

## Description

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:

	  - m == mat.length

	  - n == mat[i].length

	  - 1 <= m, n <= 10^4

	  - 1 <= m * n <= 10^4

	  - mat[i][j] is either 0 or 1.

	  - There is at least one 0 in mat.

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

## Example Test Cases (raw)

```
[[0,0,0],[0,1,0],[0,0,0]]
[[0,0,0],[0,1,0],[1,1,1]]
```

## Approach

_Tags: Array, Dynamic Programming, Breadth-First Search, Matrix_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
