class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long tsum = accumulate(nums.begin(), nums.end(), 0LL);
        long long mindif = LLONG_MAX;

        int idx = -1;
        long long lsum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            lsum += nums[i];
            long long rsum = tsum - lsum;
            long long lavg = lsum / (i + 1);
            long long ravg;
            if ((n - i - 1) > 0)
                ravg = rsum / (n - i - 1);
            else
                ravg = 0;
            long long diff = abs(lavg - ravg);
            if (diff < mindif) {
                mindif = diff;
                idx = i;
            }
        }
        return idx;
    }
};