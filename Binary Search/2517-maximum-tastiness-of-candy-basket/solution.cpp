class Solution {
public:
    int check(int m,vector<int>& nums,int k)
    {
        int a=nums.size();
        int cnt=1;
        int last=nums[0];
        for(int i=1;i<a;i++)
        {
            if(abs(nums[i]-last)>=m)
            {
                cnt++;
                last=nums[i];
                if(cnt>=k) return 1;
                
            }
        }
        return 0;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int l=1;
        sort(price.begin(),price.end());
        int h=price.back()-price.front();
        int ans=0;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(check(m,price,k))
            {
                ans=m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans;
        
    }
};
