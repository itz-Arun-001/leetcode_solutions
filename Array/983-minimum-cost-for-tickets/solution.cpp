class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int a=dp[i+1]+cost[0];
            int j=lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
            int b=dp[j]+cost[1];
            int k=lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
            int c=dp[k]+cost[2];
            dp[i]=min({a,b,c});
        }
        return dp[0];
    }
};
