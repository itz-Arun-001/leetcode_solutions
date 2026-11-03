# 453. Minimum Moves to Equal Array Elements

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

## Description

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

Example 1:

Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

Example 2:

Input: nums = [1,1,1]
Output: 0

Constraints:

	  - n == nums.length

	  - 1 <= nums.length <= 10^5

	  - -10^9 <= nums[i] <= 10^9

	  - The answer is guaranteed to fit in a 32-bit integer.

## Example Test Cases (raw)

```
[1,2,3]
[1,1,1]
```

## Approach

_Tags: Array, Math_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
