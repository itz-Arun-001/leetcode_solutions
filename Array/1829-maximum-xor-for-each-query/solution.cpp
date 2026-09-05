class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int xr = 0;
        for (int x : nums) {
            xr ^= x;
        }
        int mask = (1 << maximumBit) - 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[n - 1 - i] = xr ^ mask;
            xr ^= nums[i];
        }
        return ans;
    }
};
