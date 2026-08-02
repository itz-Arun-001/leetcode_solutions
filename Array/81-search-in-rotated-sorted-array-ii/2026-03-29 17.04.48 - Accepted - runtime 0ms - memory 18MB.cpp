class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]==target)   return true;
            else if(target <nums[m])  {
                    r=m-1;

            }
            else
                l=m+1;
        }
        return false;
       
    }
};