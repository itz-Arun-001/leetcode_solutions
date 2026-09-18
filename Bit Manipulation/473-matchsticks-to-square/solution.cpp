class Solution {
public:
    bool help(vector<int>&nums,int idx,vector<int>& b,int& t,int& n)
    {
        if(idx==n) return true;
        for(int i=0;i<4;i++)
        {
            if(b[i]+nums[idx]>t) continue;
            b[i]+=nums[idx];
            if (help(nums,idx+1,b,t,n))
                return true;
            b[i]-=nums[idx];
            if (b[i]==0)
                break;
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int tot=0;
        for(int& x:nums) tot+=x;
        if(tot%4!=0 ) return false;
        int t=tot/4;
        vector<int>b(4,0);
          sort(nums.rbegin(), nums.rend());
        int n=nums.size();
        return help(nums,0,b,t,n);
    }
};
