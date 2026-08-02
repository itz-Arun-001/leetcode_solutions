class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            rsum -= nums[i];
            ans[i] = (rsum - nums[i] * (n - i - 1)) + (nums[i] * i - lsum);

            lsum += nums[i];
        }
        return ans;
    }
};
/*
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>psum(nums.size()+1,0);
        int a=0;
        psum[0]=a;
        for(int i=0;i<psum.size()-1;i++)
        {
            a+=nums[i];
            psum[i+1]=a;
        }
       int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int l=i;
           int r=n-i+1;
            nums[i]=(nums[i]*l-psum[i])+((psum[n]-psum[i+1])-nums[i]*(n-i-1));
        }
        return nums;


    }
};*/