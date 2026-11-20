class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        if(n<=3) return 0;
        //if(n==3) return min({nums[0],nums[1],nums[2]});
        sort(nums.begin(),nums.end());
        ans=min({nums[n-1]-nums[2],nums[n-2]-nums[1],nums[n-3]-nums[0]});
        return ans;
    }
};
