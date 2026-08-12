/*class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int mxsize=INT_MIN;
        int cnt=0;
        if(nums.size()==1) return 1;
        for(int x:nums)
        {
            if(mp[x]>=k)
            {
               
                cnt=0;
                mp.clear();
                mp[x]++;
                cnt++;
            }
            else{
                cnt++;
                mp[x]++;
            }
             mxsize=max(mxsize,cnt);
        }
        return mxsize;
        
    }
};*/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int mxsize=INT_MIN;
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            mp[nums[r]]++;
            while(mp[nums[r]]>k)
            {
                mp[nums[l]]--;
                l++;
            }
            mxsize=max(mxsize,r-l+1);
        }
        return mxsize;
    }
};
