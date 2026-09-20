class Solution {
public:
int ans=0;
void dfs(vector<vector<char>>& grid,int r,int c,vector<bool>& visited,int &m,int& n) {
        if(r<0||r>=m||c<0||c>=n)
            return;
        if(visited[r*n+c])
            return;
        if(grid[r][c]=='0') return;
        visited[r*n+c]=true;;
        dfs(grid,r+1,c,visited,m,n); 
        dfs(grid,r-1,c,visited,m,n); 
        dfs(grid,r,c+1,visited,m,n); 
        dfs(grid,r,c-1,visited,m,n); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<bool> visited(m*n,false);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'&&visited[i*n+j]==false)
                {
                    ans++;
                    dfs(grid,i,j,visited,m,n);
                }
            }
        }
        return ans; 
    }
};
