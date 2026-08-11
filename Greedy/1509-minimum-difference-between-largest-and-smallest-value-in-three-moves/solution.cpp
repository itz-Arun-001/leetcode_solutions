class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<5) return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int l=0,r=3;
        
        while(l<=3){
        ans=min(ans,nums[n-1-r]-nums[l]);
        l++;
        r--;
        }
        return ans;
        
    }
};
