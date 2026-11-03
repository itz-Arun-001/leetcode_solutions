class Solution {
public:
      const int MOD=1000000007;
    int help(int r,int c,int &m,int &n,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
       
        if(dp[r][c]!=-1) return dp[r][c];
        long long ans=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n){
                if(grid[nr][nc]>grid[r][c])
                {
                    ans=(ans+help(nr,nc,m,n,grid,dp))%MOD;
                }
            }
        }
        dp[r][c]=ans;
        return ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
      
        vector<vector<int>>dp(m,vector<int>(n,-1));
        long long tot=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                tot=(tot+help(i,j,m,n,grid,dp))%MOD;
            }
        }
        return tot;
    }
};
