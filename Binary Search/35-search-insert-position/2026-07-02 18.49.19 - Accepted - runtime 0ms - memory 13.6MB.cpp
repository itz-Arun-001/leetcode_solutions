/*class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        //int flag=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {  // flag=1;
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;

            }
            else
                high=mid-1;
        }
        return low;


    }
};

*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int tar) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid]>= tar) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};