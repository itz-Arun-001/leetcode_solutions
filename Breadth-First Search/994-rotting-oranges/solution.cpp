class Solution {
public:
bool check(vector<vector<int>>& grid,int& r,int &c,int& m,int& n)
    {
        if(r<0||r>=m||c<0||c>=n) return false;
        if(grid[r][c]==1) return true;
        return false;
        

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                   q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty() && fresh>0)
        {
            int s=q.size();
            while(s--)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int nr=dr[k]+r;
                    int nc=dc[k]+c;
                    if(check(grid,nr,nc,m,n))
                    {
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            ans++;
        }
        return fresh>0?-1:ans;
    }
};
