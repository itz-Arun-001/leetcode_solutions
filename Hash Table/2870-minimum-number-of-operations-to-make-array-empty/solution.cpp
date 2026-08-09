class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x: nums)
        {
            mp[x]++;
        }
        int ans=0;
        for(auto it:mp)
        {
           int x = it.second;
            if (x == 1) return -1; 
            ans += (x + 2) / 3;
        }
        return ans;
    }
};
