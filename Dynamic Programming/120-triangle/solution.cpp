/*class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size()-2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m);
        for(int i=0;i<m;i++)
        {
            dp[i]=vector<int>(triangle[m-1].size(),INT_MAX);
        }
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                // dp[i+1][j]=min(dp[i+1][j],triangle[i+1][j]+dp[i][j]);
                // dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+triangle[i+1][j+1]);
                if(j > 0)
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1] + triangle[i][j]);
                if(j < triangle[i-1].size())
                    dp[i][j] = min(dp[i][j],dp[i-1][j]+triangle[i][j]);
            }
        }
        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};
