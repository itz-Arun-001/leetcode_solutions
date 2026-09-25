class Solution {
public:
void help(vector<vector<int>>& grid,vector<bool>& visited,int r,int&m,int&n)
{
    //if(r<0||r>=m||c<0||c>=n) return;
    //if(grid[r][c]==0||visited[r*n+c]==true) return;
    if(r<0||r>=m) return ;
    visited[r]=true;
    for(int i=0;i<n;i++)
    {
        if(grid[r][i]==1&&!visited[i])
        {
            help(grid,visited,i,m,n);
        }
    }
    
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        int n=isConnected[0].size();
        int cnt=0;
        vector<bool> visited(m,false);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1&&visited[i]==false)
                {
                    cnt++;
                    help(isConnected,visited,i,m,n);
                }
            }
        }
        return cnt;
    }
};
