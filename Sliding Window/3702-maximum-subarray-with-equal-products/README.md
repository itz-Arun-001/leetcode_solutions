# 3411. Maximum Subarray With Equal Products

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/maximum-subarray-with-equal-products/

## Description

You are given an array of positive integers nums.

An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

	  - prod(arr) is the product of all elements of arr.

	  - gcd(arr) is the GCD of all elements of arr.

	  - lcm(arr) is the LCM of all elements of arr.

Return the length of the longest product equivalent subarray of nums.

Example 1:

Input: nums = [1,2,1,2,1,1,1]

Output: 5

Explanation:

The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.

Example 2:

Input: nums = [2,3,4,5,6]

Output: 3

Explanation:

The longest product equivalent subarray is [3, 4, 5].

Example 3:

Input: nums = [1,2,3,1,4,5,1]

Output: 5

Constraints:

	  - 2 <= nums.length <= 100

	  - 1 <= nums[i] <= 10

## Example Test Cases (raw)

```
[1,2,1,2,1,1,1]
[2,3,4,5,6]
[1,2,3,1,4,5,1]
```

## Approach

_Tags: Array, Math, Sliding Window, Enumeration, Number Theory_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
