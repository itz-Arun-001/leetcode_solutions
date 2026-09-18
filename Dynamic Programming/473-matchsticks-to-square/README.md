# 473. Matchsticks to Square

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/matchsticks-to-square/

## Description

You are given an integer array matchsticks where matchsticks[i] is the length of the i^th matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

Example 1:

Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Constraints:

	  - 1 <= matchsticks.length <= 15

	  - 1 <= matchsticks[i] <= 10^8

## Example Test Cases (raw)

```
[1,1,2,2,2]
[3,3,3,3,4]
```

## Approach

_Tags: Array, Dynamic Programming, Backtracking, Bit Manipulation, Bitmask_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
