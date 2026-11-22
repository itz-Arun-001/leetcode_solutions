class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int Dfs(int node,vector<int>&ans)
    {
        int size=1;
        for(int& m : mp[node])
        {
           size+=Dfs(m,ans);
        }
        return ans[node]=size;
    }
    void dfs(int node,vector<bool>&vis,vector<int>& prev,vector<int>& parent,string &s)
    {
        if(vis[node]) return;
        char c=s[node]-'a';
        int pre=prev[c];
        if(pre!=-1)
        {
            parent[node]=pre;
        }
        prev[c]=node;
        vis[node]=true;
        for(int& m: mp[node])
        {
            dfs(m,vis,prev,parent,s);   
        }
        prev[c]=pre;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        for(int i=0;i<n;i++)
        {
            mp[parent[i]].push_back(i);
        }
        vector<bool>vis(n,false);
        vector<int>prev(26,-1);
        dfs(0,vis,prev,parent,s);
        mp.clear();
        for(int i=0;i<n;i++)
        {
            mp[parent[i]].push_back(i);
        }
        vector<int>ans(n,0);
        Dfs(0,ans);
        // for(int i=0;i<n;i++)
        // {
        //     ans[i]=Dfs(i);
        // }
        return ans;
    }
};
