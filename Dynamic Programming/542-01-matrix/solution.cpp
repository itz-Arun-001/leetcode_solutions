class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dis(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                   {
                     dis[i][j]=0;
                      q.push({i,j});
                   }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&dis[nr][nc]==-1)
                {
                    dis[nr][nc]=dis[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return dis;


    }
};
