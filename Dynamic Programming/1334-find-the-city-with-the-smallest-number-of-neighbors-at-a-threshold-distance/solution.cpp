class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        //vcetor<vector<int>>path(n,vector<int>(n,0));
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            adj[i][i]=0;
        }
       for(auto e:edges)
       {
            int a=e[0],b=e[1],c=e[2];
            adj[a][b]=c;
            adj[b][a]=c;
       }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    //if(adj[i][k]!=INT_MAX||adj[k][i]!=INT_MAX)
                    if(((long long)adj[i][k]+adj[k][j])<INT_MAX)
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int mn=0;
        vector<int>cnt(n,0);
        for(int i=0;i<n;i++)
        {
            //int cit=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&adj[i][j]!=INT_MAX&&adj[i][j]<=dt)
                {
                    cnt[i]++;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(cnt[i]<=cnt[mn])
            {
                mn=i;
            }
        }
        return mn;
    }
};


/*class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<int>cnt(n,0);
        vector<int>wt(n,0);
        vector<vector<int>>adj(n);
        for(auto& ed:edges)
        {
            int a=ed[0],b=ed[1],c=ed[2];
            if(c<=dt) {
                cnt[a]++;
                wt[a]+=c;
                wt[b]+=c;
                cnt[b]++;
            }
        }
        int ct=0;
        int mn=cnt[0];
        int m=wt[0];
        for(int i=1;i<n;i++)
        {
            if(cnt[i]<mn)
            {
                mn=cnt[i];
                m=wt[i];
                ct=i;
            }
            else if(cnt[i]==mn)
            {
                if(wt[i]>wt[ct])
                {
                    m=wt[i];
                    ct=i;
                    mn=cnt[i];
                }
            }
        }
        return ct; 
    }
};*/
