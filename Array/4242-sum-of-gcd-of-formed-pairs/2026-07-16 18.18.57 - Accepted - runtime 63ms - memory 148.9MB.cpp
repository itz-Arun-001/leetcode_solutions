class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        //vector<long long> ans(nums.size(),0);
        int mi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            mi=max(mi,nums[i]);
            nums[i]=gcd(nums[i],mi);


        }
        long long a=0;
        int l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(l<r)
        {
            a+=gcd(nums[l],nums[r]);
            l++;r--;
        }
        return a;
        
    }
};