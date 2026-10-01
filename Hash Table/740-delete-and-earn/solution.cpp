class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx=INT_MIN;
        for(int x:nums){
            mp[x]++;
            mx=max(mx,x);
        }
        //vector<int>dp(mx+1,0);
        // dp[0]=0;
        // dp[1]=mp[1];
        int curr;
        int prev2=0,prev1=mp[1];
        for(int i=2;i<=mx;i++)
        {
            // dp[i]=max(dp[i-1],dp[i-2]+i*mp[i]);
            curr=max(prev1,mp[i]*i+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};
