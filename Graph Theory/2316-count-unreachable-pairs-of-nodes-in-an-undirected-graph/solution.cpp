class Solution {
public:
    long long dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        if (visited[node]) return 0;
        visited[node]=true;
        long long cnt=1;
        for (int next:adj[node]) {
            cnt+=dfs(next,adj,visited);
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for (auto x:edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n, false);
        long long ans=0;
        long long prev=0;
        for (int i=0;i<n;i++) {
            if(!visited[i]){
                long long size=dfs(i,adj,visited);
                ans+=prev*size;
                prev+=size;
            }
        }
        return ans;
    }
};
