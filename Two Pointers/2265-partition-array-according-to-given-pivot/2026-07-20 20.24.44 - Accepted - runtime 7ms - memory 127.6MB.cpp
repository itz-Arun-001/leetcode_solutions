/*class Solution {
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
};*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int left=0;;
        int right=nums.size()-1;
        vector<int>ans(right+1,0);
        int l=0;
        int r=nums.size()-1;
        while(left<nums.size()&&right>=0)
        {
            if(nums[left]<pivot)
            {
                ans[l]=nums[left];
                l++;
                
            }
            if(nums[right]>pivot)
            {
                ans[r]=nums[right];
                r--;
            }
            left++;right--;
        }
        while(l<=r)
        {
            ans[l]=pivot;
            l++;
        }
        return ans;
    }
};