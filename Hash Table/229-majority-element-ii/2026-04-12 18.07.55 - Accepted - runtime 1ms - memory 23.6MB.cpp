class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while(i < n) {
            int j = i;
            
            // move j until element changes
            while(j < n && nums[j] == nums[i]) {
                j++;
            }
            
            int count = j - i;
            
            if(count > n/3) {
                ans.push_back(nums[i]);
            }
            
            i = j; // move to next new element
        }
        
        return ans;
    }
};