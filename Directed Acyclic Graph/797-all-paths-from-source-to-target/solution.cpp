class Solution {
public:
vector<vector<int>>ans;
 void dfs(int x,vector<vector<int>>& adj,vector<int>& temp,int des)
    {
        if(x==des)
        {
            ans.push_back(temp);
            return;
        }
        for(int i:adj[x])
        {
            temp.push_back(i);
            dfs(i,adj,temp,des);
            temp.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> temp;
        temp.push_back(0);
        dfs(0,graph,temp,n - 1);
        return ans;

    }
};
