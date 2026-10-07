# 301. Remove Invalid Parentheses

**Difficulty:** Hard
**Link:** https://leetcode.com/problems/remove-invalid-parentheses/

## Description

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3:

Input: s = ")("
Output: [""]

Constraints:

	  - 1 <= s.length <= 25

	  - s consists of lowercase English letters and parentheses '(' and ')'.

	  - There will be at most 20 parentheses in s.

## Example Test Cases (raw)

```
"()())()"
"(a)())()"
")("
```

## Approach

_Tags: String, Backtracking, Breadth-First Search_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
