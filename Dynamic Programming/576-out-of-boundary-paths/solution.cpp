class Solution {
public:
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>>(m,vector<int>(n,0)));
        int up,down,right,left;
        const int MOD=1000000007;
        for(int k=1;k<=maxMove;k++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    up=(i-1<0)?1:dp[k-1][i-1][j]%MOD;
                    down=(i+1>=m)?1:dp[k-1][i+1][j]%MOD;
                    right=(j+1>=n)?1:dp[k-1][i][j+1]%MOD;
                    left=(j-1<0)?1:dp[k-1][i][j-1]%MOD;
                    dp[k][i][j]=(1LL*left+right+up+down)%MOD;
                }
            }
        }
        return dp[maxMove][sr][sc];
    }
};
