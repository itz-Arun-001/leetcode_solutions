# 1192. Critical Connections in a Network

**Difficulty:** Hard
**Link:** https://leetcode.com/problems/critical-connections-in-a-network/

## Description

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:

Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

Constraints:

	  - 2 <= n <= 10^5

	  - n - 1 <= connections.length <= 10^5

	  - 0 <= ai, bi <= n - 1

	  - ai != bi

	  - There are no repeated connections.

## Example Test Cases (raw)

```
4
[[0,1],[1,2],[2,0],[1,3]]
2
[[0,1]]
```

## Approach

_Tags: Depth-First Search, Graph Theory, Biconnected Component, Bridge (Graph)_

_(Add your approach notes here -- LeetCode's public API doesn't
expose editorial/approach write-ups, so this is left for you to
fill in.)_
