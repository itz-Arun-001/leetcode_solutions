class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        int tot=0;
        vector<int>sum(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            sum[i]=sum[i+1]+piles[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int M=1;M<=n;M++)
            {
                for(int x=1;x<=2*M&&i+x<=n;x++)
                {
                    dp[i][M]=max(dp[i][M],sum[i]-dp[i+x][max(M,x)]);
                }
            }
        }
        return dp[0][1];
    }
};
