class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for (int i = 0; i < n; i++) { //
            if (i ==n - 1) {
                if (nums[i] > nums[0])
                    c++;
            }

            else {
                if (nums[i] > nums[i + 1])
                    c++;
            }
        }
        return (c > 1) ? false : true;
    }
};