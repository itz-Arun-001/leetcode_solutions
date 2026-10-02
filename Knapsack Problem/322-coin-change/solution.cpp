class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int>dp(amt+1,INT_MAX-1);
        dp[0]=0;
        for(int x:coins)
        {
            for(int i=1;i<=amt;i++)
            {
                if(i-x>=0)
                    dp[i]=min(dp[i],dp[i-x]+1);
            }
        }
        return dp[amt]==INT_MAX-1?-1:dp[amt];
    }
};
