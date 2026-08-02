class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
                mp[nums[i]]++;
        }
        int m=mp.size();
        int max=0,index;
        for(auto it:mp)
        {
            if(max<it.second)
            {
                max=it.second;
                index=it.first;

            }
        }
        return index;
    }
};