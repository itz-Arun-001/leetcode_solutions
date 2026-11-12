class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i+len<=n;i++)
            {
                int j=i+len-1;
                //if(s[i]!=s[j])
                //{
                    dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);
                //}
               // else{
                    for(int k=i+1;k<=j;k++)
                    {
                        if(s[i]==s[k])
                        {
                            dp[i][j]=min(dp[i][j],(k==i+1?0:dp[i+1][k-1])+dp[k][j]);
                        }
                    }
                //}
            }
        }
        return dp[0][n-1];
    }
};
