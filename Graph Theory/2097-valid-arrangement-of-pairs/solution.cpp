class Solution {
public:
        int n;
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indeg,outdeg; 
        vector<vector<int>>ans;
        void dfs(int node)
        {
            while(!adj[node].empty()){
                int n=adj[node].back();
                adj[node].pop_back();
                dfs(n);
                 ans.push_back({node,n});
            }
           
        }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        n=pairs.size();
        for(auto &p:pairs)
        {
            indeg[p[1]]++;
            outdeg[p[0]]++;
            adj[p[0]].push_back(p[1]);
        }
        int st=pairs[0][0];
        for(auto &p:pairs)
        {
            int node=p[0];
            if(outdeg[node]==indeg[node]+1)
            {
                st=node;
                break;
            }
        }
        dfs(st);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
