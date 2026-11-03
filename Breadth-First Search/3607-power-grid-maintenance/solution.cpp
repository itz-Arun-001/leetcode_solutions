class Solution {
public:
    vector<vector<int>>adj;
    vector<set<int>>grid;
    void dfs(int node,vector<bool>& vis,set<int>& temp,vector<int>& id,int &c)
    {
        vis[node]=true;
        id[node]=c;
        temp.insert(node);
        for(int n:adj[node])
        {
            if(!vis[n]) dfs(n,vis,temp,id,c);

        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        adj.assign(c+1,{});
        grid.clear();
        for(auto &it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(c+1,false);
        set<int>temp;
        vector<int>id(c+1);
        int cnt=0;
        for(int i=1;i<=c;i++)
        {

            if(!vis[i]){
                temp.clear();
                dfs(i,vis,temp,id,cnt);
                cnt++;
               // grid.push_back(vector<int>(temp.begin(),temp.end()));
               grid.push_back(temp);
            }
        }
        vector<bool>online(c+1,true);
        vector<int>ans;
        for(auto &it:queries)
        {
            int a=it[0];
            int b=it[1];
            if(a==2) {
                online[b]=false;
                grid[id[b]].erase(b);
            }
            else{
                if(online[b]) ans.push_back(b);
                else{
                    if(grid[id[b]].empty())
                        ans.push_back(-1);
                    else
                        ans.push_back(*grid[id[b]].begin());
                }
            }
        }
        return ans;

    }
};
