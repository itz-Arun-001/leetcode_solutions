class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
          int n=nums.size();
        if(n==0) return 0;
        if( n==1) return 1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int minidx;
      
        int maxidx;
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i] < mini) {
            mini = nums[i];
            minidx=i;
            }
            if (nums[i] > maxi) {
            maxi = nums[i];
            maxidx=i;
            }


        }
        int a=min(minidx+1,n-minidx);
        int b=min(maxidx+1,n-maxidx);
      /*  if (minidx < n / 2 && maxidx < n / 2) {
            return max(minidx, maxidx) + 1;
        }
        if (minidx >= n / 2 && maxidx >= n / 2) {
            return n - min(minidx, maxidx);
        }
        return a+b;*/
        int l=max(minidx, maxidx) + 1;
        int r=n-min(minidx, maxidx);
        int both=a+b;
        return min({l,r,both});
    }
};
