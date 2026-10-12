class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& states)
    {
        if(states[node]==1) return false;
        if(states[node]==2) return true;
        states[node]=1;
        for(int n:adj[node])
        {
            if(!dfs(n,adj,states))
            {
                return false;
            }
            
        }
        states[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>states(n,0);
        for(int i=0;i<n;i++)
        {
            if(states[i]==0)
            {
                dfs(i,graph,states);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        { 
            if(states[i]==2)
                ans.push_back(i);
        }
        return ans;
    }
};
