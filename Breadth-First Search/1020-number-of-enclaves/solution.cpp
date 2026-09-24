/*class Solution {
public:
    int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
    bool help(vector<vector<int>>& grid,int r,int c,vector<vector<bool>>& ispos)
    {    
        if(r-1>0||r+1<m||c+1<n||c-1>0){
            if(ispos[r][c]==true) return true;
        }
       
        for(int i=0;i<4;i++)
        {
            int nr=dr[i]+r;
            int nc=dc[i]+c;
            if(help(grid,nr,nc,ispos)) return true;
        }
        return false;

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt;
        vector<vector<bool>>ispos(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0||i=m-1||j=n-1) ispos[i][j]=true;
                if(!help(grid,i,j,ispos))
                    cnt++;
            }
        }
        return cnt;
    }
};*/
class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    bool help(vector<vector<int>>& grid,int r,int c,vector<vector<bool>>& visited,int& cells,int &m,int& n)
    {
        if(r<0||r>= m||c<0||c>=n)
            return false;
        if(grid[r][c]==0||visited[r][c])
            return false;
        visited[r][c]=true;
        cells++;
        bool pos=(r==0||r==m-1||c==0||c==n-1);
        for (int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if (help(grid,nr,nc,visited,cells,m,n))
                pos=true;
        }
        return pos;
    }
    int numEnclaves(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for (int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!visited[i][j])
                {
                    int cells=0;
                    bool pos =help(grid,i,j,visited,cells,m,n);
                    if (!pos)
                        cnt+=cells;
                }
            }
        }
        return cnt;
    }
};
