class Solution {
public:
    int help(string s,int idx,int&n,vector<int>& dp)
    {
        if(idx==n){
            return 1;
        }
        if(s[idx]=='0' )return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pos=help(s,idx+1,n,dp);
        if(idx+1<n)
        { 
            int num=(s[idx]-'0')*10+(s[idx+1]-'0');
            if(num>=10&&num<=26) 
                pos+=help(s,idx+2,n,dp);
        }
        return dp[idx]=pos;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return help(s,0,n,dp);
    }
};
