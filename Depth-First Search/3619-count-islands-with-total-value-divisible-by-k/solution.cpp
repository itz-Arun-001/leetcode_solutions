class Solution {
public:
    void dfs(vector<vector<int>> &grid,int r,int c,int &m,int &n,vector<bool>&visited,long long& temp)
    {
         if(r<0||r>=m||c<0||c>=n) return;
         if(grid[r][c]==0||visited[r*n+c])return;
        visited[r*n+c]=true;
        temp+=grid[r][c];
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int p=0;p<4;p++)
        {
                dfs(grid,r+dr[p],c+dc[p],m,n,visited,temp);
        }
        
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
       long long temp;
        vector<bool>visited(m*n,false);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i*n+j]&&grid[i][j]!=0)
                {
                    temp=0;
                 dfs(grid,i,j,m,n,visited,temp);
                 if(temp%k==0) ans++;

                }
            }
        }
        return ans;
    }
};
