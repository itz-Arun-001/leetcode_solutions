class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==1)
            {
                if(mp[nums[i]-1]!=0||mp[nums[i]+1]!=0)
                {
                    continue;
                }
                // if(i<n-1&&(nums[i+1]==nums[i]-1||nums[i+1]==nums[i]+1))
                // {
                //     continue;
                // }
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
