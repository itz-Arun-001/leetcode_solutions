class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c,vector<bool>& visited,int &m,int& n)
    {
        if(r<0||r>=m||c<0||c>=n)
            return 0;
        if(visited[r*n+c]) return 0;
        if(grid[r][c]==0) return 0;
        visited[r*n+c]=true;
        int temp=1+dfs(grid,r+1,c,visited,m,n)+dfs(grid,r-1,c,visited,m,n)+dfs(grid,r,c-1,visited,m,n)+dfs(grid,r,c+1,visited,m,n);
        return temp;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<bool>visited(n*m,false);
        int temp=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!visited[i*n+j])
                {
                temp=0;
                temp=dfs(grid,i,j,visited,m,n);
                ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};
