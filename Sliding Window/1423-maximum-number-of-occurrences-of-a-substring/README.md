# 1297. Maximum Number of Occurrences of a Substring

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

## Description

Given a string s, return the maximum number of occurrences of any substring under the following rules:

	  - The number of unique characters in the substring must be less than or equal to maxLetters.

	  - The substring size must be between minSize and maxSize inclusive.

Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 occurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.

Constraints:

	  - 1 <= s.length <= 10^5

	  - 1 <= maxLetters <= 26

	  - 1 <= minSize <= maxSize <= min(26, s.length)

	  - s consists of only lowercase English letters.

## Example Test Cases (raw)

```
"aababcaab"
2
3
4
"aaaa"
1
3
3
```

## Approach

_Tags: Hash Table, String, Sliding Window_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
