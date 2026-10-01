class Solution {
public:
    int cnt=0;
    void help(vector<int>& nums,int &n,int& t,int idx,int &curr)
    {
        if(idx==n)
        {
             if(curr==t)
                cnt++;
             return;
        }
        //if(t<curr) return;
        //for(int i=idx;i<n;i++)
        //{
            curr+=nums[idx];
            help(nums,n,t,idx+1,curr);
            curr-=nums[idx];
            curr-=nums[idx];
            help(nums,n,t,idx+1,curr);
            curr+=nums[idx];
        //}
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int curr=0;
        help(nums,n,target,0,curr);
        return cnt;
    }
};


// ---- submission 2026-10-01 18:07:17 ----

/*class Solution {
public:
    int cnt=0;
    void help(vector<int>& nums,int &n,int& t,int idx,int &curr)
    {
        if(idx==n)
        {
             if(curr==t)
                cnt++;
             return;
        }
        //if(t<curr) return;
        //for(int i=idx;i<n;i++)
        //{
            curr+=nums[idx];
            help(nums,n,t,idx+1,curr);
            curr-=nums[idx];
            curr-=nums[idx];
            help(nums,n,t,idx+1,curr);
            curr+=nums[idx];
        //}
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int curr=0;
        help(nums,n,target,0,curr);
        return cnt;
    }
};*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        for(int x:nums) s+=x;
        vector<int>dp(2*s+1,0);
        dp[s]=1;
         for (int x : nums) {
            vector<int> newdp(2*s+1,0);
            for (int i=0; i<2*s+1;i++) {
                if (dp[i]!= 0) {
                    newdp[i+x]+=dp[i];
                    newdp[i-x]+=dp[i];
                }
            }
            dp=newdp;
        }
        if(target<-s||target>s) return 0;
        return dp[target+s];
    }
};
