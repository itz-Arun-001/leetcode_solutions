class Solution {
public:
    bool complete(unordered_map<int,vector<int>>& mp)
    {
        int n=mp.size();
        for(auto& p:mp)
        {
            if(p.second.size()!=n-1)
                return false;
        }
        return true;
    }
    void dfs(int node,vector<bool>&vis,vector<vector<int>>& adj,unordered_map<int,vector<int>>&mp)
    {
        vis[node]=true;
        mp[node]=adj[node];
        for(int n:adj[node])
        {
            if(!vis[n]){
                dfs(n,vis,adj,mp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        for(auto& e:edges)
        {
            int a=e[0];
            int b=e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,vector<int>>mp;
            if(!vis[i])
            {
                dfs(i,vis,adj,mp);
                if(complete(mp))
                    ans++;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     bool complete(unordered_map<int,vector<int>>& mp)
//     {
//         int n=mp.size();
//         for(auto :mp)
//         {
//             if()
//         }
//     }
//     void dfs(int node,vector<bool>&vis,vector<vector<int>>& adj,unordered_map<int,vector<int>>&mp)
//     {
//         vis[node]=true;
//         for(int n:adj[node])
//         {
//             if(!vis[n]){
//                 mp[node].push_back(n);
//                 mp[n].push_back(node);
//                 dfs(n,vis,adj,mp);
//             }
//         }
//     }
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>>adj(n);
//         vector<bool>vis(n,false);
//         for(auto& e:edges)
//         {
//             int a=e[0];
//             int b=e[1];
//             adj[a].push_back(b);
//             adj[b].push_back(a);
//         }
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             unordered_map<int,vector<int>>mp;
//             if(!vis[i])
//             {
//                 dfs(i,vis,adj,mp);
//                 if(complete(mp))
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };
