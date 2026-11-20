class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int>dp1(n+1,0),dp2(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dp1[i]=dp1[i-1]+(s[i-1]=='1');
            dp2[i]=dp2[i-1]+(s[i-1]=='0');
               
        }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++)
        {
            ans=min(ans,dp1[i]+dp2[n]-dp2[i]);
        }
        return ans;
    }
};
