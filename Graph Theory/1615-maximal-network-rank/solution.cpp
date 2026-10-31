class Solution {
public:
    bool isconnected(int src,int dst,vector<vector<int>>&adj)
    {
        if(src==dst) return true;
        //vis[src]=true;
        for(int n :adj[src])
        {
           if(n==dst) return true;
        }
        return false;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>deg(n,0);
        vector<vector<int>>adj(n);
        for(auto &it:roads)
        {
            deg[it[0]]++;
            deg[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int mx=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ans=deg[i]+deg[j];
              
                if(isconnected(i,j,adj))
                    ans--;
                mx=max(mx,ans);
            }
        }
        return mx;
    }
};
