class Solution {
public:
    bool solve(vector<int>& nums,vector<int>&b,int idx,int t) {
        if (idx==nums.size())
            return true;
        for (int i=0;i<b.size();i++) {
            if (b[i]+nums[idx]>t)
                continue;
            b[i]+=nums[idx];
            if (solve(nums,b,idx+1,t))
                return true;
            b[i]-=nums[idx];
            if (b[i] == 0)
                break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for (int x:nums)
            total+=x;
        if (total%k!=0)
            return false;
        int target=total/k;
        vector<int> bucket(k,0);
        sort(nums.rbegin(),nums.rend());
        return solve(nums,bucket,0,target);
    }
};
