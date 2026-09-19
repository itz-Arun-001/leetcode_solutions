class Solution {
public:
    void help(vector<vector<int>>& grid,vector<vector<bool>>& visited,int &r,int& c,int& temp,int& tempmx,int&m,int& n)
    {
        if(grid[r][c]==0||visited[r][c]==true) return;
        int dr[] ={-1,1,0,0};
        int dc[]={0,0,-1,1};
        temp+=grid[r][c];
        visited[r][c]=true;
        tempmx=max(tempmx,temp);
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
             if (nr>=0&&nr<m&&nc>=0&&nc<n) 
             {
                if(grid[nr][nc]!=0&&visited[nr][nc]==false)
                {
                     help(grid,visited,nr,nc,temp,tempmx,m,n);

                }
            }
        }
        temp-=grid[r][c];
        visited[r][c]=false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxans=0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            int temp=0;
            int tempmx=0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0){
                help(grid,visited,i,j,temp,tempmx,m,n);
                maxans=max(maxans,tempmx);
                }
            }
        }
        return maxans;
    }
};
