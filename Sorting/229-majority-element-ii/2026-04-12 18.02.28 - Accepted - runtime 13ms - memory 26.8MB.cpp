class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        int n= nums.size();
       
        for(int i=0;i<n;i++)
        {
            //if(mp.find(nums[i])!=mp.end())
                mp[nums[i]]++;

        }
        int m=mp.size();
        int a=n/3;
        for(auto it:mp)
        {
            if(it.second>a)
                ans.push_back(it.first);
        }
        return ans;

        
    }
};