class Solution {
public:
    int ans = INT_MAX;
    void dfs(int node, vector<vector<pair<int,int>>>& adj, 
             vector<int>& visited) {
        visited[node]=1;
        for (auto x :adj[node]) {
            int nxt=x.first;
            int w=x.second;
            ans=min(ans,w);
            if (!visited[nxt]) {
                dfs(nxt,adj,visited);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto road:roads) {
            int u=road[0];
            int v=road[1];
            int w=road[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>visited(n+1,0);
        dfs(1,adj,visited);
        return ans;
    }
};
