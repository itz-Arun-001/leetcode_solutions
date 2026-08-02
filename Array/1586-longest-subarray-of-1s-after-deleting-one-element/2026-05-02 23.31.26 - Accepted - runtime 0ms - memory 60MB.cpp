class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxs=INT_MIN;
        int l=0,c=0;
        for(int r=0;r<n;r++)

        {
            if(nums[r]==0)  c++;
             while(c>1)
            {
                if(nums[l] == 0) c--;
                l++;
                
            }

           
            maxs=max(maxs,r-l);



        }
        return maxs==INT_MIN?0:maxs;
    }
};