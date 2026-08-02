class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int l=0,c=0,psum=0;
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int r=0;r<n;r++)
        {
            psum+=nums[r];
            int p=psum-goal;
            if(mp.count(p))  ans+=mp[p];
            mp[psum]++;
       
        }
        return ans;
    }
};