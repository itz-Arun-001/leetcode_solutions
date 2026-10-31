class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int mxlen=1;
        int stidx=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i+len<=n;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j])
                {
                    if(len==2||dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                        if(len>mxlen)
                        {
                            mxlen=len;
                            stidx=i;
                        }
                    }
                }
            }
        }
        return s.substr(stidx,mxlen);
    }
};
/*class Solution {
public:
    int expand(string& s,int i,int j,int n)
    {
        while(i>=0&&j<n&&s[i]==s[j])
        {
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
       int n=s.size();
       int mxidx=-1;
       int mx=INT_MIN;
       int len1=INT_MIN;
       int len2=INT_MIN;
       for(int i=0;i<n;i++)
       {
         len1=expand(s,i,i,n);
         len2=expand(s,i,i+1,n);
         int len=max(len1,len2);
         if(mx<len)
         {
            mx=len;
            mxidx=i-(len-1)/2;
         }
       }
       return s.substr(mxidx,mx);

    }
};*/
