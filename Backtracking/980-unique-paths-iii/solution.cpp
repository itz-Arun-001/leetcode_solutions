class Solution {
public:
    int ans=0;
 
    void help(vector<vector<int>>& grid,int r,int c,int& req,int& avail,int& m,int& n,vector<vector<bool>>&visited)
        {
        if(grid[r][c] == 2)
        {
            if(req == avail)
                ans++; 
             return;
        }
        if(grid[r][c]==-1)
        {
            return;
        }
        else{
            
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};
                for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                   if(grid[nr][nc] != -1 && visited[nr][nc] == false)
                        {
                            visited[nr][nc]=true;
                            avail++;
                            help(grid,nr,nc,req,avail,m,n,visited);
                            visited[nr][nc]=false;
                            avail--;

                        }
                   }
                
            }
        }  
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int reqcnt=0;
        int m = grid.size();
        int n = grid[0].size();
        int str,stc,endr,endc;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    str=i;
                    stc=j;
                    reqcnt++;
                }
                else if(grid[i][j]==2)
                {
                    endr=i;
                    endc=j;
                    reqcnt++;
                }
                else if(grid[i][j]==-1) continue;
                else{
                    reqcnt++;
                }
            }
        }
        visited[str][stc]=true;
        int avail = 1;
        help(grid,str,stc,reqcnt,avail,m,n,visited);
        return ans;
    }
};
