class Solution {
public:
   bool check(vector<int>& nums,long long &m,long long &k)
    {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ans+=(nums[i]/m);
            if(ans>=k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=1;
        long long h=accumulate(candies.begin(),candies.end(),0LL);
        if(h<k) return 0;
        long long ans=INT_MIN;
        while(l<=h)
        {
            long long m=l+(h-l)/2;
            if(check(candies,m,k))
            {
                ans=max(ans,m);
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
        
    }
};
