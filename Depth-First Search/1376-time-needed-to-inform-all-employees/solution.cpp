class Solution {
public:
    int ans=0;
    void dfs(int &id,vector<int>& manager,vector<int>& time,vector<vector<int>>&adj,int curr)
    {
        if(adj[id].size()==0) {
            ans=max(ans,curr);
            return;
        }
        for(int n :adj[id])
        {
            dfs(n,manager,time,adj,curr+time[id]);
        }
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<bool>know(n,false);
        know[headID]=true;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        int cur=0;
        dfs(headID,manager,informTime,adj,cur);
        return ans;

    }
};
