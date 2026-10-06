class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(auto x:pre)
        {
            adj[x[1]].push_back(x[0]);
        }
        vector<int>incnt(n,0);
        for(auto x: pre)
        {
            incnt[x[0]]++;
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++)
        {
            if(incnt[i]==0)
                q.push(i); 
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int x:adj[node])
            {
                incnt[x]--;
                if(incnt[x]==0)
                    q.push(x);
            }
        }
        if(topo.size()==n) return topo;
        return {};


    }
};
