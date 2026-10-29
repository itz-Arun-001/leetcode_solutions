class Solution {
public:
struct table
{
    bool known;
    int dist;
    int path;
};
int n;
vector<vector<int>>adj;
//int adjMatrix[n][n];
//TableEntry T[n];
vector<table>t;
void addEdge(int u, int v, int w)
{
    adj[u][v] = w;
    adj[v][u] = w;
}

int smallestUnknown()
{
    int mind=INT_MAX;
    int idx =-1;
    for (int i=0;i<n;i++)
    {
        if (!t[i].known&&t[i].dist<mind)
        {
            mind=t[i].dist;
            idx=i;
        }
    }
    return idx;
}
int prims(int src)
{
    for (int i=0;i<n;i++)
    {
        t[i].known=false;
        t[i].dist=INT_MAX;
        t[i].path=-1;
    }
    t[src].dist = 0;
    while (true)
    {
        int v=smallestUnknown();
        if (v==-1)
            break;
        t[v].known = true;
        for (int w =0;w<n;w++)
        {
            if (adj[v][w]!=INT_MAX&&!t[w].known)
            {
                if (adj[v][w]<t[w].dist)
                {
                    t[w].dist=adj[v][w];
                    t[w].path=v;
                }
            }
        }
    }
    int tot=0;
    int cnt=0;
    cout << "\nEdge\tWeight\n";
    for (int i = 0; i < n; i++)
    {
        if (i != src && t[i].path != -1)
        {
            cout << t[i].path << " - " << i
                 << "\t" << t[i].dist << endl;

            tot+= t[i].dist;
            cnt++;
        }
    }

    if (cnt!= n - 1)
    {
        cout << "Graph is disconnected. MST does not exist.\n";
        return -1;
    }
    else
    {
        cout << "Total MST weight = "
             << tot << endl;
    }
    return tot;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        n=points.size();
        if(n==0) return 0;
        adj.assign(n,vector<int>(n,INT_MAX));
        t.assign(n,{false,INT_MAX,-1});
        for(int i=0;i<n;i++)
        {
            adj[i][i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                addEdge(i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
            }
        }
        int ans=prims(0);
        if(ans==-1) return 0;
        return ans;

    }
};
