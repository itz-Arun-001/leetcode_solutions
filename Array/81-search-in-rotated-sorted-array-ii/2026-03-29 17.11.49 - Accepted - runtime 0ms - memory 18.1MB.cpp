class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        for(auto a:nums)
        {
            if(a==target)
            {
                return true;

            }
        }
        return false;
    }
};