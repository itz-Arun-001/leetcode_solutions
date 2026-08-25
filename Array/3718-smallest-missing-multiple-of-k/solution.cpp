class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(int i=1;i<INT_MAX;i++)
        {

            if(mp[i*k]==0) return i*k;
        }
        return -1;
    }
};
