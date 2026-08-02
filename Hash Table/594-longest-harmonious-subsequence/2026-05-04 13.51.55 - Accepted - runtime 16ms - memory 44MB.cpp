class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int temp=0;
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i]+1))
            {
                temp=mp[nums[i]]+mp[nums[i]+1];
            }
            ans=max(ans,temp);
        }
        return ans;


        
    }
};