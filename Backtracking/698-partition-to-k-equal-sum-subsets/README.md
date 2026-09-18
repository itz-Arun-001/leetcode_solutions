# 698. Partition to K Equal Sum Subsets

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

## Description

Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false

Constraints:

	  - 1 <= k <= nums.length <= 16

	  - 1 <= nums[i] <= 10^4

	  - The frequency of each element is in the range [1, 4].

## Example Test Cases (raw)

```
[4,3,2,3,5,2,1]
4
[1,2,3,4]
3
```

## Approach

_Tags: Array, Dynamic Programming, Backtracking, Bit Manipulation, Memoization, Bitmask_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
