//DFS - TRAVERSAL 
/*class Solution {
public:
    bool dfs(int &node,int &dest,vector<vector<int>>& adj,vector<bool>& visited)
    {
        if(node==dest) return true;
        visited[node]=true;
        for(auto &a: adj[node])
        {
            if(!visited[a])
            {
                if(dfs(a,dest,adj,visited)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for( auto& e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<bool> visited(n,false);
        return dfs(source,destination,adj,visited);
    }

};*/

//BFS _ TRAVERSAL

class Solution {
public:
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for( auto& e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<bool> visited(n,false);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(node==destination) return true;
            for(int &a: adj[node])
            {
                if(!visited[a])
                {
                    visited[a]=true;
                    q.push(a);
                }
            }
        }
        return false;
    }
};

        
