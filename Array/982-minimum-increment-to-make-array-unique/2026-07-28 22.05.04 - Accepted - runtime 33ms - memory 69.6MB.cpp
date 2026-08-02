class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int next = prev + 1;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= prev) {
                ans += next - nums[i];
                nums[i] = next++;
                prev = nums[i];
            }
            if (nums[i] > prev) {
                prev = nums[i];
                next = prev + 1;
            }
        }
        return ans;
    }
};