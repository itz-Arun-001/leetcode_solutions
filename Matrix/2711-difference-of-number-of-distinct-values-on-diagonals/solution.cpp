class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
          

            for(int j=0;j<m;j++)
            {
                  unordered_set<int>s1;
                unordered_set<int>s2;
                int x=i,y=j;
                while(x>=0&&y>=0)
                {
                    x--;
                    y--;
                    if(x<0||y<0) break;
                    s1.insert(grid[x][y]);
                }
                x=i;
                y=j;
                while(x<n&&y<m)
                {
                     x++;
                    y++;
                    if(x>=n||y>=m) break;
                    s2.insert(grid[x][y]);
                }
            ans[i][j]=abs((int)s1.size()-(int)s2.size());
            }
            
        }
        return ans;
    }
};
