class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vist(n,-1);
        int t=0;
        int ans=-1;
        for(int i=0;i<n;i++) {
            if(vist[i]!=-1)
                continue;
            int node=i;
            int start=t;
            while(node!=-1&&vist[node]==-1) {
                vist[node]=t++;
                node=edges[node];
            }
            if(node!=-1&&vist[node]>=start) {
                ans=max(ans,t-vist[node]);
            }
        }
        return ans;
    }
};
