class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indeg(n);
        for(auto &it:edges)
        {
            indeg[it[1]]++;

        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0) ans.push_back(i);
        }
        return ans;
    }
};

/*class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis)
    {
        vis[node]=true;
        for(int n: adj[node])
        {
            if(!vis[n])
            {
                dfs(n,adj,vis);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
           // adj[it[1]].push_back(it[0]);

        }
        vector<bool>visited(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans.push_back(i);
                dfs(i,adj,visited);
            }

        }
        return ans;
    }
};*/
