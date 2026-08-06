# 739. Daily Temperatures

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/daily-temperatures/

## Description

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the i^th day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:

	  - 1 <= temperatures.length <= 10^5

	  - 30 <= temperatures[i] <= 100

## Example Test Cases (raw)

```
[73,74,75,71,69,72,76,73]
[30,40,50,60]
[30,60,90]
```

## Approach

_Tags: Array, Stack, Monotonic Stack_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
