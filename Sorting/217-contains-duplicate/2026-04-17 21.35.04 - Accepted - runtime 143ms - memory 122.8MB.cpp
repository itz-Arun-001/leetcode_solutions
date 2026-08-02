class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]].size()>1)    return true;
        }
        return false;
    }
};