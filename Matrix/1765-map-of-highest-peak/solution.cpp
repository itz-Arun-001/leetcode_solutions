class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>hei(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j]==1)
                {
                    hei[i][j]=0;
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
                int nr=r+dr[i];
                int nc=dc[i]+c;
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&hei[nr][nc]==-1)
                {
                    hei[nr][nc]=1+hei[r][c];
                    q.push({nr,nc});
                }
            }
        }
        return hei;
    }
};
