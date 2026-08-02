class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int l = 0, sum = 0, ans = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 == 1) sum++;   // count odd

            while (sum > k) {
                if (nums[l] % 2 == 1) sum--;
                l++;
            }

            ans += (r - l + 1);
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};