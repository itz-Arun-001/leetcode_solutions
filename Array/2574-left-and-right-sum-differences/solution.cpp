class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int l=0,r=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();

        vector<int>ans(nums);

        for(int i=0;i<n;i++)
        {
            r -= nums[i];
            ans[i] = abs(l - r);
            l += nums[i];
        }
        return ans;
        
    }
};
