class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
    int i = n - 2;

    // Step 1: Find breakpoint
    while(i >= 0 && nums[i] >= nums[i+1])
        i--;

    if(i >= 0) {
        int j = n - 1;

        // Step 2: Find just bigger element
        while(nums[j] <= nums[i])
            j--;

        // Step 3: Swap
        swap(nums[i], nums[j]);
    }

    // Step 4: Reverse suffix
    reverse(nums.begin() + i + 1, nums.end());
    }
};