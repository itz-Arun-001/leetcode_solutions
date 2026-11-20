class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin() , nums.end());
        long long ans=0,l=0,r=0,temp=0,target,sum=0;
        while(l<n&&r<n)
        {
           target=nums[r];
            sum+=nums[r];
            temp=target*(r-l+1)-sum;
            while(temp>k)
           {
            sum-=nums[l];
            l++;
            temp=target*(r-l+1)-sum;
           }
           ans=max(ans,r-l+1);
           r++;
        }
        return ans;
    }
};
