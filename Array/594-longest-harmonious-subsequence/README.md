# 594. Longest Harmonious Subsequence

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/longest-harmonious-subsequence/

## Description

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]

Output: 2

Explanation:

The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

Example 3:

Input: nums = [1,1,1,1]

Output: 0

Explanation:

No harmonic subsequence exists.

Constraints:

	  - 1 <= nums.length <= 2 * 10^4

	  - -10^9 <= nums[i] <= 10^9

## Example Test Cases (raw)

```
[1,3,2,2,5,2,3,7]
[1,2,3,4]
[1,1,1,1]
```

## Approach

_Tags: Array, Hash Table, Sliding Window, Sorting, Counting_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
