class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int ans=0,currwidth=0;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            mx=0;
            currwidth=0;
            for(int j=i-1;j>=0;j--)
            {
                mx=max(mx,books[j][1]);
                if(currwidth+books[j][0]>shelfWidth){
                     break;
                }
                dp[i]=min(dp[i], dp[j] + mx);
                currwidth+=books[j][0];
                
                
            }
        }
        return dp[n];
    }
};
