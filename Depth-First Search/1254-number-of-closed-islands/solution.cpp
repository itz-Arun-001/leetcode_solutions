class Solution {
public:
    
    bool help(vector<vector<int>>&grid,int r,int c,int&m,int& n,vector<bool>& visited)
    {
        
        if(r<0||r>=m||c<0||c>=n) return false;
        if(grid[r][c]==1||visited[r*n+c]) return true;
        visited[r*n+c]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        // for(int i=0;i<4;i++)
        // {
        //     int nr=dr[i]+r;
        //     int nc=dc[i]+c;
        //     if(help(grid,nr,nc,m,n,visited))
        //         return true;
        // }
        bool up=help(grid,r+dr[0],c+dc[0],m,n,visited);
        bool down=help(grid,r+dr[1],c+dc[1],m,n,visited);
        bool left=help(grid,r+dr[2],c+dc[2],m,n,visited);
        bool right=help(grid,r+dr[3],c+dc[3],m,n,visited);
        return left&&right&&up&&down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<bool>visited(n*m,false);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0&&visited[i*n+j]==false)
                {
                    bool temp=help(grid,i,j,m,n,visited);
                    if(temp) ans++;
                }
            }
        }
        return ans;
    }
};
