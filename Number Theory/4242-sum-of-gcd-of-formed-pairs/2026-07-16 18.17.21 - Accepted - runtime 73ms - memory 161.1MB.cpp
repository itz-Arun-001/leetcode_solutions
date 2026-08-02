class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> ans(nums.size(),0);
        int mi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            mi=max(mi,nums[i]);
            ans[i]=gcd(nums[i],mi);


        }
        long long a=0;
        int l=0,r=ans.size()-1;
        sort(ans.begin(),ans.end());
        while(l<r)
        {
            a+=gcd(ans[l],ans[r]);
            l++;r--;
        }
        return a;
        
    }
};