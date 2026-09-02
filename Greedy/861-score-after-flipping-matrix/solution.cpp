class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<n;j++)
                {
                    grid[i][j]^=1;
                }
            }
        }
        for(int j=0;j<n;j++)
        {   
            int onecnt=0;
            for(int i=0;i<m;i++)
            {
                if(grid[i][j]==1) onecnt++;
            }
            int zerocnt=m-onecnt;
            if(zerocnt>onecnt)
            {
                for(int i=0;i<m;i++)
                 {
                    grid[i][j]^=1;
                 }
              }
            
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int val=0;
            for(int j=0;j<n;j++)
            {
                int temp=0;
                if(grid[i][j]==1)
                {
                    temp=1;
                }
                val=val*2+temp;
            }
            ans+=val;
        }
        return ans;

    }
};
