
class Solution {
public:
    void dfs(int v,vector<vector<int>>&adj,vector<bool>&vis)
    {
        vis[v]=true;
        for(auto w:adj[v])
        {
            if(!vis[w])dfs(w,adj,vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adj(n);
        for(int i = 0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                c++;
            }
        }
        return n-c;
    }
};
