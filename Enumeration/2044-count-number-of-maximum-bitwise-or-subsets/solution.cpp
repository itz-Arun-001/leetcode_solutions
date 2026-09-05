class Solution {
public:
    int maxor=0;
    int cnt=0;
    void help(vector<int>&nums,int temp,int idx)
    {
        int n=nums.size();
       if(n==idx)
        {
            if(maxor==temp)
                cnt++;
            return;
        }
        help(nums,temp,idx+1);
        help(nums,temp|nums[idx],idx+1);


    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n;i++)
        {
            maxor|=nums[i];
        }
        help(nums,0,0);
        return cnt;
    }
};
