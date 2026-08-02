class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX;
        int low=0;
        int high=nums.size()-1;
        //sort(nums.begin(),nums.end());
        while(low<high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[high]) 
                low=mid+1;
            else    high=mid;
        }
        return nums[low];



        
    }
};