class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n==0)
            return ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        vector<vector<int>>adj(n);
        vector<int>deg(n);
        for (auto &e:edges)
        {
            deg[e[0]]++;
            deg[e[1]]++;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int>q;
        for (int i=0;i<n;i++)
        {
            if(deg[i]==1) q.push(i);
        }
        while(n>2)
        {
            int s=q.size();
            n-=s;
            while(s>0)
            {
                int node=q.front();
                q.pop();
                for(int no:adj[node])
                {
                    deg[no]--;
                    if(deg[no]==1)
                        q.push(no);
                }
                s--;
                
            }
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};
