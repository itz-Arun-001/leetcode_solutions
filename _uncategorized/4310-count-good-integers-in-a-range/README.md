# 3966. Count Good Integers in a Range

**Difficulty:** Hard
**Link:** https://leetcode.com/problems/count-good-integers-in-a-range/

## Description

You are given three integers l, r and k.

A number is considered good if the absolute difference between every pair of adjacent digits is at most k.

Return the number of good integers in the range [l, r] (inclusive).

The absolute difference between values x and y is defined as abs(x - y).

Example 1:

Input: l = 10, r = 15, k = 1

Output: 3

Explanation:

	  - The good integers in the range are 10, 11, and 12.

	  - For 10, abs(1 - 0) = 1.

	  - For 11, abs(1 - 1) = 0.

	  - For 12, abs(1 - 2) = 1.

	  - All these differences are at most k = 1. Thus, the answer is 3.

Example 2:

Input: l = 201, r = 204, k = 2

Output: 2

Explanation:

	  - The good integers in the range are 201 and 202.

	  - For 201, abs(2 - 0) = 2 and abs(0 - 1) = 1.

	  - For 202, abs(2 - 0) = 2 and abs(0 - 2) = 2.

	  - Thus, the answer is 2.

Constraints:

	  - 10 <= l <= r <= 10^15

	  - 0 <= k <= 9

## Example Test Cases (raw)

```
10
15
1
201
204
2
```

## Approach

_Tags: N/A_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
