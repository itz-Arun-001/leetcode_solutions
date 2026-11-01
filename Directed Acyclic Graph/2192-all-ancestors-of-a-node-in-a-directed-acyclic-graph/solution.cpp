class Solution {
public:
  
    void help(int node,vector<vector<int>>& adj,vector<bool>& vis,set<int>& s)
    {
        vis[node]=true;
        for(int n:adj[node])
        {
            s.insert(n);
            if(vis[n]==false)
            {
                help(n,adj,vis,s);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
          vector<vector<int>>ans;
        for(auto &it:edges)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
          set<int>s;
        for(int i=0;i<n;i++)
        {
            vis.assign(n,false);
            s.clear();
          help(i,adj,vis,s);
            ans.push_back(vector<int>(s.begin(),s.end()));
        }
        return ans;

    }
};
