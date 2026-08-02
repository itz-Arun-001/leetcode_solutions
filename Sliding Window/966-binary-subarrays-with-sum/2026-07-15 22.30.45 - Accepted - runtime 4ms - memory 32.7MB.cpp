/*class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int l=0,c=0,psum=0;
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int p;
        for(int r=0;r<n;r++)
        {
            psum+=nums[r];
            p=psum-goal;
            if(mp.count(p))  ans+=mp[p];
            mp[psum]++;
       
        }
        return ans;
    }
};*/

class Solution {
public:
    int atmost(vector<int>& nums,int g)
    {
        if(g<0) return 0;
        int l=0,r=0,ans=0,s=0;
        while(r<nums.size())
        {
            s+=nums[r];
            while(s>g)
            {
                s=s-nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};

