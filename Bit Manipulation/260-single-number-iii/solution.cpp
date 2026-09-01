/*class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map <int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        for(auto it: mp)
        {
            if(it.second==1)    ans.push_back(it.first);
        }
        return ans;
        
        
    }
};*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        for(int& num:nums)
        {
            ans^=num;
        }
     long long x = ans;
long long bit = x & (-x);
        int a=0,b=0;
        for(int& num: nums)
        {
            if(num & bit)
                a ^= num;
            else
                b ^= num;

        }
        return {a,b};
    }
};
