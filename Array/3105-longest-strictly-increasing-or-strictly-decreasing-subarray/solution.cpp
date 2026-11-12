class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        //vector<int>dp1(n,1),dp2(n,1);
        int ans=1,inc=1,dec=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                //dp1[i]=dp1[i-1]+1;
                inc++;
            }
            //else dp1[i]=1;
            else inc=1;
            if(nums[i]<nums[i-1])
            {
               // dp2[i]=dp2[i-1]+1;
               dec++;
            }
            //else dp2[i]=1;
            else dec=1;
            //ans=max(ans,max(dp1[i],dp2[i]));
            ans=max(ans,max(inc,dec));
        }

        return ans;
    }
};
