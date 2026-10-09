class Solution {
public:
    // bool ispalindrome(string s)
    // {
    //     int n=s.size();
    //     int i=0,j=n-1;
    //     while(i<j)
    //     {
    //         if(s[i]!=s[j]) return false;
    //     }
    //     return true;
    // }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(i+1<n&&j-1>=0)
                        dp[i][j]=2+dp[i+1][j-1];
                }
                else 
                    if(i+1<n&&j-1>=0)
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];

        

    }
};
