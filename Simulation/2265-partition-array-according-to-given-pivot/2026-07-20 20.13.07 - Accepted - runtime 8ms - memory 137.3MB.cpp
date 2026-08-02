class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int j = 0;
        vector<int> left;
        vector<int> right;
        int nc = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot)
                left.push_back(nums[i]);
            else if (nums[i] == pivot)
                nc++;
            else
                right.push_back(nums[i]);
        }
        while (nc > 0) {
            left.push_back(pivot);
            nc--;
        }
        for (int i = 0; i < right.size(); i++) {
            left.push_back(right[i]);
        }
        return left;
    }
};