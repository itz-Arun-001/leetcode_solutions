class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        while(true)
        {   
            ans.push_back(nums);
            int i=n-2;
            while(i>=0&&nums[i]>=nums[i+1])
                i--;
            if(i<0)
                break;
            int j=n-1;
            while(nums[j]<=nums[i])
                j--;
            swap(nums[j],nums[i]);
            reverse(nums.begin()+i+1,nums.end());
            
        }
        return ans;

        
    }
};