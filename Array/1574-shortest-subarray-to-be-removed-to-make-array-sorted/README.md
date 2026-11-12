# 1574. Shortest Subarray to be Removed to Make Array Sorted

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

## Description

Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

Example 2:

Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

Example 3:

Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.

Constraints:

	  - 1 <= arr.length <= 10^5

	  - 0 <= arr[i] <= 10^9

## Example Test Cases (raw)

```
[11,10,18,14,12,11,16,20,13,11]
[17,32,32,29,4,29,19,5,26,35,35,6,10,27,11,35,0,31]
[1,8,34,2,3,22,18,27,3,1,0,12,21,23,8,7,17]
```

## Approach

_Tags: Array, Two Pointers, Binary Search, Stack, Monotonic Stack_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
