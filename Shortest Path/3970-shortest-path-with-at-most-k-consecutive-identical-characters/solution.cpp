class Solution {
public:
    vector<vector<int>>dijkstra(int n,vector<vector<int>> adj[],int src,string& label,int k)
    {
        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));
        dist[src][1]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,1}});
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second.first;
            int cnt=pq.top().second.second;
            pq.pop();
            if(dis>dist[node][cnt]) continue;
            for(auto& it:adj[node])
            {
                int nxtnode=it[0];
                int wt=it[1];
                int newcnt;
                if(label[node]==label[nxtnode])    
                    newcnt=cnt+1;
                else newcnt=1;
                if(newcnt>k) continue;
                if(dis==INT_MAX) continue;
                if(dis+wt<dist[nxtnode][newcnt])
                {
                    dist[nxtnode][newcnt]=dis+wt;
                    pq.push({dist[nxtnode][newcnt],{nxtnode,newcnt}});
                }
                
            }
        }
        return dist;
    }
    
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>>adj[n];
        for(auto &it:edges)
        {
            int a=it[0],b=it[1],c=it[2];
            adj[a].push_back({b,c});
            //adj[b].push_back({a,c});
        }
       vector<vector<int>>dist=dijkstra(n,adj,0,labels,k);
       int ans = INT_MAX;
        for(int i=1;i<=k;i++)
            ans=min(ans,dist[n-1][i]);
        return (ans==INT_MAX)?-1:ans;
    }
};
