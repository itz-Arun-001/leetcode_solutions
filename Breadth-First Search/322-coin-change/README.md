# 322. Coin Change

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/coin-change/

## Description

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

Constraints:

	  - 1 <= coins.length <= 12

	  - 1 <= coins[i] <= 2^31 - 1

	  - 0 <= amount <= 10^4

## Example Test Cases (raw)

```
[1,2,5]
11
[2]
3
[1]
0
```

## Approach

_Tags: Array, Dynamic Programming, Breadth-First Search, Knapsack Problem, Complete Knapsack_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
