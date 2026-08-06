# 3754. Concatenate Non-Zero Digits and Multiply by Sum I

**Difficulty:** Easy
**Link:** https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

## Description

You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

Example 1:

Input: n = 10203004

Output: 12340

Explanation:

	  - The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.

	  - The sum of digits is sum = 1 + 2 + 3 + 4 = 10.

	  - Therefore, the answer is x * sum = 1234 * 10 = 12340.

Example 2:

Input: n = 1000

Output: 1

Explanation:

	  - The non-zero digit is 1, so x = 1 and sum = 1.

	  - Therefore, the answer is x * sum = 1 * 1 = 1.

Constraints:

	  - 0 <= n <= 10^9

## Example Test Cases (raw)

```
10203004
1000
```

## Approach

_Tags: Math_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
