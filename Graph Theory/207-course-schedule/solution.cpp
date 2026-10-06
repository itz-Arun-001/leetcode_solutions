class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto x:pre)
        {
            adj[x[1]].push_back(x[0]);
        }
        vector<int>incnt(n,0);
        for(auto x:pre)
        {
            incnt[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(incnt[i]==0)
                q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto n: adj[node])
            {
                incnt[n]--;
                if(incnt[n]==0) q.push(n);
            }

        }
        return topo.size()==n;
    }
};
