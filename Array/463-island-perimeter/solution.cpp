class Solution {
public:
    bool check(vector<vector<int>>& grid,int& r,int &c,int& m,int& n)
    {
        if(r<0||r>=m||c<0||c>=n) return true;
        if(grid[r][c]==0) return true;
        return false;
        

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int dr[]={-1,1,0,0};
                    int dc[]={0,0,-1,1};
                    for(int k=0;k<4;k++)
                    {
                        int nr=dr[k]+i;
                        int nc=dc[k]+j;
                        if(check(grid,nr,nc,m,n))
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
