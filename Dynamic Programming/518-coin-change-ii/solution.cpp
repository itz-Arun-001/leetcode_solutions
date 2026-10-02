class Solution {
public:
    int change(int amt, vector<int>& coins) {
        vector<int>dp(amt+1,0);
        dp[0]=1;
        for(int x:coins)
        {
            for(int i=1;i<=amt;i++)
            {
                if(i-x>=0)
                    if (dp[i-x]<=INT_MAX-dp[i])
                        dp[i]+=dp[i-x];
            }
        }
        return dp[amt];
    }
};
