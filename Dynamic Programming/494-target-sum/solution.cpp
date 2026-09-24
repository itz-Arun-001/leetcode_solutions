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
