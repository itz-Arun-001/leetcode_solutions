class Solution {
    int t=1;
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&id,vector<int>&low,vector<vector<int>>&ans)
    {
        visited[node]=true;
        id[node]=t;
        low[node]=t;
        t++;
        for(int &n: adj[node])
        {
            if(n==parent) continue;
            if(!visited[n])
            {
                dfs(n,node,adj,visited,id,low,ans);
                low[node]=min(low[n],low[node]);
                if(low[n]>id[node]) {
                    ans.push_back({node,n});
                }

            }
            else{
                low[node]=min(low[n],low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }
        vector<int> id(n);
        vector<int>low(n);
        vector<bool>visited(n,false);
        vector<vector<int>>ans;
        dfs(0,-1,adj,visited,id,low,ans);
        return ans;
    }
};
