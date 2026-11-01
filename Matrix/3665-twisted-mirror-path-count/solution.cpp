class Solution {
public:
    const int MOD = 1000000007;
    int help(int r,int c,int m,int n,vector<vector<vector<int>>>& dp,int dir,vector<vector<int>>& grid)
    {
        if(r<0||r>=m||c<0||c>=n)return 0;
        if(r==m-1&&c==n-1) return 1;
        if(dp[r][c][dir]!=-1) return dp[r][c][dir];
        int ans=0;
        if(grid[r][c]==0){
                ans=(help(r,c+1,m,n,dp,0,grid)+help(r+1,c,m,n,dp,1,grid))%MOD;
        }
        else
        {
                if(dir==0) ans=help(r+1,c,m,n,dp,1,grid)%MOD;
                else if(dir==1) ans=help(r,c+1,m,n,dp,0,grid)%MOD;

        }
        dp[r][c][dir]=ans%MOD;
        return ans%MOD;



    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
         help(0,0,m,n,dp,0,grid);
         return dp[0][0][0];
    }
};
