class Solution {
public:
    int dfs(int node,int parent,vector<vector <pair<int ,int>>>&adj)
    {
        int t=0;
        for(auto it:adj[node])
        {
            if(it.first==parent)
                continue;
            t+=it.second;
            t+=dfs(it.first,node,adj);
        }
        return t;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:connections)
        {
            int u=it[0],v=it[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        return dfs(0,-1,adj);
    }
};
