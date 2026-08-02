class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int temp=nums[i];
            int ans=0;
            while(nums[i]>0)
            {
                ans+=nums[i]%10;
                nums[i]/=10;

            }
            nums[i]=ans;
            if(min>nums[i]) min=nums[i];
        }
        return min;
        
    }
};