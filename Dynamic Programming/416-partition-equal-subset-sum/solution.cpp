class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(int x:nums)
        {
            s+=x;
        }
        if(s%2!=0) return false;
        int target=s/2;
        vector<int>dp(target+1,false);
        dp[0]=1;
        int n=nums.size();
        for(int x:nums)
        {
            for(int i=target;i>=x;i--)
                dp[i]=dp[i]||dp[i-x];
        }
        return dp[target];
        

    }
};
