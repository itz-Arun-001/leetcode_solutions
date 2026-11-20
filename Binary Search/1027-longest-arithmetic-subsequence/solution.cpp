class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1;
        vector<unordered_map<int,int>>dp(n);
        int d;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                d=nums[i]-nums[j];
                dp[i][d]=max(dp[i][d],dp[j][d]+1);
                ans=max(ans,dp[i][d]);
            }
        }
        return ans+1;
    }
};
