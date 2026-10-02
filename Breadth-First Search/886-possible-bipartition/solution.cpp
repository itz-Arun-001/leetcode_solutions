class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj ,vector<int>& color)
    {
        for(int n: adj[node])
        {
            if(color[n]==color[node]) return false;
            if(color[n]==-1){ 
                color[n]=!color[node];
                if(!dfs(n,adj,color)) 
                    return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m=dislikes.size();
        vector<int>color(n+1,-1);
        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++)
        {
             int x=dislikes[i][0];
            int y=dislikes[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);

        }

        for(int i=1;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!dfs(i,adj,color)) return false;
            }
        }
        return true;
    }
};
