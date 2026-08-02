class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int max=0,index=-1;
        for(auto m : mp)
        {
            if(m.second>max&&m.first%2==0)
            {
                max=m.second;
                index=m.first;
            }
        }
        return index;
        
    }
};