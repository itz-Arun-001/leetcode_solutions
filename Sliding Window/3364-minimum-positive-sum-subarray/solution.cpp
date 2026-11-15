
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int left, int right) {
        int ans=INT_MAX;
      int n=nums.size();
        for(int r=0;r<n;r++)
        {
            int curr=0;
            for(int l=r;l>=0&&r-l+1<=right;l--)
            {
                curr+=nums[l];
                if(r-l+1>=left&&curr>0)
                {
                    ans=min(ans,curr);
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};

/*class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int left, int right) {
        int ans=INT_MAX;
        int n=nums.size();
        int curr=0;
        int l=0;
        int r=0;
        for(r=0;r<n;r++)
        {
            curr+=nums[r];
             while(r-l+1>right)
            {
                curr-=nums[l];
                l++;

            }
            if(r-l+1<=right&&r-l+1>=left&&curr>0)
            {
                ans=min(ans,curr);
            }
           
        }
        return (ans<=0||ans==INT_MAX)?-1:ans;
    }
};*/
