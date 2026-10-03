/*class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int>freq1(26,0),freq2(26,0);
        for(char c: word1)
        {
            freq1[c-'a']++;
        }
        for(char c: word2)
        {
            freq2[c-'a']++;
        }
        int c=0;
        for(int i=0;i<26;i++)
        {
            if(freq1[i]!=0&&freq2[i]!=0)
                 c+=min(freq1[i],freq2[i]);
        }
        int m=word1.size();
        int n=word2.size();
        return (m+n)-2*c;
    }
};*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
            
        }
        int c=dp[m][n];
        return (m+n)-2*c;
    }
};
