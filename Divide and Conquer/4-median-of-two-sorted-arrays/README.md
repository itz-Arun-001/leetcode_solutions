# 4. Median of Two Sorted Arrays

**Difficulty:** Hard
**Link:** https://leetcode.com/problems/median-of-two-sorted-arrays/

## Description

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

	  - nums1.length == m

	  - nums2.length == n

	  - 0 <= m <= 1000

	  - 0 <= n <= 1000

	  - 1 <= m + n <= 2000

	  - -10^6 <= nums1[i], nums2[i] <= 10^6

## Example Test Cases (raw)

```
[1,3]
[2]
[1,2]
[3,4]
```

## Approach

_Tags: Array, Binary Search, Divide and Conquer_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
