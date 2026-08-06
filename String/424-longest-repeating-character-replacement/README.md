# 424. Longest Repeating Character Replacement

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/longest-repeating-character-replacement/

## Description

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

Constraints:

	  - 1 <= s.length <= 10^5

	  - s consists of only uppercase English letters.

	  - 0 <= k <= s.length

## Example Test Cases (raw)

```
"ABAB"
2
"AABABBA"
1
```

## Approach

_Tags: Hash Table, String, Sliding Window_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
