class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minv = INT_MAX;
        int n = nums.size();
        int sum = 0, l = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum >= target) {
                sum -= nums[l];
                minv = min(minv, r - l + 1);

                l++;
            }
        }
        return (minv == INT_MAX) ? 0 : minv;
    }
};