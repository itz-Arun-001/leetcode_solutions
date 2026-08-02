class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //vector<int>ans;
        int n=nums.size();
        int l=0;
        int maxi=0;
        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
            {
                l=r+1;
            }
          //  ans.push_back(nums[r]);
            maxi=max(maxi,r-l+1);


        }
        return maxi;
        
    }
};