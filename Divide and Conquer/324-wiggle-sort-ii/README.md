# 324. Wiggle Sort II

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/wiggle-sort-ii/

## Description

Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.

Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]

Constraints:

	  - 1 <= nums.length <= 5 * 10^4

	  - 0 <= nums[i] <= 5000

	  - It is guaranteed that there will be an answer for the given input nums.

Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?

## Example Test Cases (raw)

```
[1,5,1,1,6,4]
[1,3,2,2,3,1]
```

## Approach

_Tags: Array, Divide and Conquer, Greedy, Sorting, Quickselect_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
