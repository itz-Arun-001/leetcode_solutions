class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0,l=0,r=0,mask=0;
        while(l<n&&r<n)
        {
            while(mask&nums[r])
            {
                mask^=nums[l];
                l++;
            }
            mask|=nums[r];
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
