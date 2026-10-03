class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& planted,vector<int>& flower)
    {
        if(planted[node]) return;
        planted[node]=true;
        vector<int> used(4,0);
        for(int n: adj[node])
        {
            if(flower[n-1]!=0)
            {
                used[flower[n-1]-1]=1;
            }
        }
        for(int i=0;i<4;i++)
        {
            if(used[i]==0)
            {
                flower[node-1]=i+1;
                break;
            }
        }
        for(int n : adj[node])
        {
            dfs(n,adj,planted,flower);  
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<int>flower(n,0);
        vector<vector<int>>adj(n+1);
        for(auto x: paths)
        {
            int a=x[0];
            int b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>planted(n,false);
        for(int i=1;i<=n;i++)
        {
            if(!planted[i])
            {
               
                dfs(i,adj,planted,flower);
            }
        }
        return flower;
    }
};
