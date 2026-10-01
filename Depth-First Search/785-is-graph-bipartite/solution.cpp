class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& color)
    {
        for(int n:graph[node])
        {
            if(color[n]==color[node])
                return false;
            if(color[n]==-1){
                color[n]=!color[node];
                if(!dfs(n,graph,color))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n+1,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,graph,color)) return false;
            }
        }
        return true;
        
    }
};
