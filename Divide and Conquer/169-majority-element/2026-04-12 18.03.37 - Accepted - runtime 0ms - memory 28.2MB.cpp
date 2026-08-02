class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
       for(auto it:nums)
       {
        mp[it]++;
       }
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