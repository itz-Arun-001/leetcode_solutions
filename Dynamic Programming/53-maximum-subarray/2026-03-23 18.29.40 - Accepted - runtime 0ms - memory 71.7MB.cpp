class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        int cur=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cur=cur+nums[i];
            if(cur<nums[i])
            {
                cur=nums[i];
            }
            if(max<cur)
            {
                max=cur;
            }
            

        }
      
        return max;
    }
};