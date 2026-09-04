/*class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int minval=INT_MAX;
        int maxval=INT_MIN;
         int is;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            minval=INT_MAX;
            maxval=INT_MIN;
            for(int j=0;j<=i;j++)
            {
                maxval=max(maxval,nums[j]);
            }
            for(int j=i;j<n;j++)
            {
                minval=min(minval,nums[j]);
            }
            int is = maxval - minval;
            if (is <= k)
            {
                return i;
            }
        }
      return -1;
        
    }
};*/
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxval(n),minval(n);
        maxval[0]=nums[0];
        minval[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            maxval[i]=max(maxval[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            minval[i]=min(nums[i],minval[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            if(maxval[i]-minval[i]<=k) return i;
        }
        return -1;
    }
};
