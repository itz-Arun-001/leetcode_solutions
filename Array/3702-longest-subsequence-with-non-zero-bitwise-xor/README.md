# 3702. Longest Subsequence With Non-Zero Bitwise XOR

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/

## Description

You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

Example 1:

Input: nums = [1,2,3]

Output: 2

Explanation:

One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

Example 2:

Input: nums = [2,3,4]

Output: 3

Explanation:

The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

Constraints:

	  - 1 <= nums.length <= 10^5

	  - 0 <= nums[i] <= 10^9

## Example Test Cases (raw)

```
[1,2,3]
[2,3,4]
```

## Approach

_Tags: Array, Bit Manipulation_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
