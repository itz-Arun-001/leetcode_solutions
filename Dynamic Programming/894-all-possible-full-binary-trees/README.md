# 894. All Possible Full Binary Trees

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/all-possible-full-binary-trees/

## Description

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Example 1:

Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:

Input: n = 3
Output: [[0,0,0]]

Constraints:

	  - 1 <= n <= 20

## Example Test Cases (raw)

```
7
3
```

## Approach

_Tags: Dynamic Programming, Tree, Recursion, Memoization, Binary Tree_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
