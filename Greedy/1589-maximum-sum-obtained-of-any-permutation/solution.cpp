class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<long long>diff(n,0);
        {
            for(auto& a:requests)
            {
                int x=a[0],y=a[1];
                diff[x]++;
                if(y+1<n)
                   diff[y+1]--;

            }
        }
        for(int i=1;i<n;i++)
        {
            diff[i]+=diff[i-1];
        }
        sort(diff.begin(),diff.end());
        sort(nums.begin(),nums.end());
        long long ans=0;
        const int MOD=1000000007;
        for(int i=0;i<n;i++)
             ans = (ans + 1LL * diff[i] * nums[i]) % MOD;
        return ans;
    }
};
