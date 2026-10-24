
class Solution {
public:
    struct Table{
        bool known;
        int dist;
        int cnt;
    };
    int size;
    vector<vector<int>>adjmat;
    vector<Table>t;
    // int smallestunknown()
    // {
    //     int mindist=INT_MAX;
    //     int idx=-1;
    //     for(int i=0;i<size;i++)
    //     {
    //         if(!t[i].known&&t[i].dist<mindist)
    //         {
    //             mindist=t[i].dist;
    //             idx=i;
    //         }
    //     }
    //     return idx;
    // }
    void dijkstra(int src,int k)
    {
        vector<int>dist(size,INT_MAX);
        dist[src]=0;
        for(int i=0;i<=k;i++)
        {
            vector<int>temp=dist;
            for(int v=0;v<size;v++)
            {
                if(dist[v]==INT_MAX) continue;
                for(int w=0;w<size;w++)
                {
                    if(adjmat[v][w]!=-1)
                    {
                        temp[w]=min(temp[w],dist[v]+adjmat[v][w]);
                    }
                }
            }
            dist=temp;
        }
        for(int i=0;i<size;i++) t[i].dist=dist[i];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        size=n;
        adjmat.assign(n,vector<int>(n,-1));
        t.assign(n,{false,INT_MAX,0});
        for(auto& f:flights)
        {
            adjmat[f[0]][f[1]]=f[2];
        }
        dijkstra(src,k);
        if(t[dst].dist==INT_MAX) return -1;
        return t[dst].dist;
    }
};




/*class Solution {
public:
    struct Table{
        bool known;
        int dist;
        int cnt;
    };
    int size;
    vector<vector<int>>adjmat;
    vector<Table>t;
    int smallestunknown()
    {
        int mindist=INT_MAX;
        int idx=-1;
        for(int i=0;i<size;i++)
        {
            if(!t[i].known&&t[i].dist<mindist)
            {
                mindist=t[i].dist;
                idx=i;
            }
        }
        return idx;
    }
    void dijkstra(int src,int k)
    {
        for(int i=0;i<size;i++){
            t[i].known=false;
            t[i].dist=INT_MAX;
            t[i].cnt=-1;
        }
        t[src].dist=0;
        t[src].cnt=0;
        while(true)
        {
            int v=smallestunknown();
            if(v==-1) break;
            t[v].known=true;
            for(int w=0;w<size;w++)
            {
                if(adjmat[v][w]!=-1&&!t[w].known&&t[v].dist!=INT_MAX)
                {
                    if(t[v].dist+adjmat[v][w]<t[w].dist&&t[v].cnt+1<=k+1)
                    {
                        t[w].dist=t[v].dist+adjmat[v][w];
                        t[w].cnt=t[v].cnt+1;
                    }
                }
            }
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        size = n;
        adjmat.assign(n,vector<int>(n,-1));
        t.assign(n,{false,INT_MAX,0});
       int a=flights.size();
       for(int i=0;i<a;i++)
       {
        adjmat[flights[i][0]][flights[i][1]]=flights[i][2];
       }
        dijkstra(src,k);
        if(t[dst].dist==INT_MAX) return -1;
        return t[dst].dist;
    }
};*/
