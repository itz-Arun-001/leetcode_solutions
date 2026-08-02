class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        for(int i=0;i<nums.size();i+=2)
        {
            int max=i;
            for(int j=i+2;j<nums.size();j+=2)
            {
                if(nums[j]<nums[max])
                    max=j;
            }
            swap(nums[i],nums[max]);
        }
        for(int i=1;i<nums.size();i+=2)
        {
            int max=i;
            for(int j=i+2;j<nums.size();j+=2)
            {
                if(nums[j]>nums[max])
                    max=j;
            }
            swap(nums[i],nums[max]);
        }
        return nums;
      
        
    }
};