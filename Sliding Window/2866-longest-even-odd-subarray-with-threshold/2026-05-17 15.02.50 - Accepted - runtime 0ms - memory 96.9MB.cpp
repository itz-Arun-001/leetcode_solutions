class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {

        int ans = 0;
        int temp = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > threshold) {
                temp = 0;
            }

            else if (temp == 0) {
                if (nums[i] % 2 == 0)
                    temp = 1;
            }

            else {
                if (nums[i] % 2 != nums[i - 1] % 2)
                    temp++;
                else {
                    if (nums[i] % 2 == 0)
                        temp = 1;
                    else
                        temp = 0;
                }
            }

            ans = max(ans, temp);
        }

        return ans;
    }
};