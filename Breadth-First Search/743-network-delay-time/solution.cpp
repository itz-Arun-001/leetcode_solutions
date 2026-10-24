class Solution {
public:
    struct Table{
        bool known;
        int dist;
        int path;
    };
    int size;
    vector<vector<int>>adjmat;
    vector<Table>t;
    int smallestunknown()
    {
        int mindist=INT_MAX;
        int idx=-1;
        for(int i=1;i<=size;i++)
        {
            if(!t[i].known&&t[i].dist<mindist)
            {
                mindist=t[i].dist;
                idx=i;
            }
        }
        return idx;
    }
    void dijkstra(int src)
    {
        for(int i=1;i<=size;i++){
            t[i].known=false;
            t[i].dist=INT_MAX;
            t[i].path=-1;
        }
        t[src].dist=0;
        while(true)
        {
            int v=smallestunknown();
            if(v==-1) break;
            t[v].known=true;
            for(int w=1;w<=size;w++)
            {
                if(adjmat[v][w]!=-1&&!t[w].known&&t[v].dist!=INT_MAX)
                {
                    if(t[v].dist+adjmat[v][w]<t[w].dist)
                    {
                        t[w].dist=t[v].dist+adjmat[v][w];
                        t[w].path=v;
                    }
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       size = n;
        adjmat.assign(n+1,vector<int>(n+1,-1));
        t.assign(n+1,{false,INT_MAX,-1});
       int a=times.size();
       for(int i=0;i<a;i++)
       {
        adjmat[times[i][0]][times[i][1]]=times[i][2];
       }
        dijkstra(k);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
           if(t[i].dist==INT_MAX) 
            return -1; 
            ans=max(ans,t[i].dist);
        }
        return ans;



    }
};
