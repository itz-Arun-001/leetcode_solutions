class Solution {
public:
     
    void dfs(int & x,vector<bool>& visited,vector<vector<int>>& adj)
    {
        if(visited[x]) return;
        int n=adj[x].size();
        visited[x]=true;
        for(int i=0;i<n;i++)
        {
            if(!visited[adj[x][i]])
            {
                dfs(adj[x][i],visited,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1)return -1;
       vector<vector<int>> adj(n);
        for(auto a: connections)
        {
            int x=a[0];
            int y=a[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(i,visited,adj);
            }
        }
        return cnt-1;
    }
};
