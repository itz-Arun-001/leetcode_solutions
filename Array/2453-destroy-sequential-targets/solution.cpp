class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n=nums.size(),idx;
        int ans=INT_MAX,mx=0;
        unordered_map<int,pair<int,int>>dp;
        for(int i=0;i<n;i++)
        {
            idx=nums[i]%space;
            if(dp.find(idx)==dp.end())
            {
                dp[idx].first=1;
                dp[idx].second=INT_MAX;
            }
            dp[idx].first=dp[idx].first+1;
            dp[idx].second=min(dp[idx].second,nums[i]);
            if(mx<dp[idx].first)
            {
                mx=dp[idx].first;
                ans=dp[idx].second;
            }
             if(mx==dp[idx].first)
            {
                ans=min(ans,dp[idx].second);
            }
        }
        return ans;
    }
};
