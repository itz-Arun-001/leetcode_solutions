class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg=INT_MIN;
        double sum =0;
        for(int i=0;i<k;i++)
            {
                sum+=nums[i];
                
            }
        maxavg=max(maxavg,sum/k);
        int n=nums.size();
        for(int i=k;i<n;i++)
            {
                 sum+=nums[i];
                sum-=nums[i-k];
                maxavg=max(maxavg,sum/k);
            }
        return maxavg;
    }
};