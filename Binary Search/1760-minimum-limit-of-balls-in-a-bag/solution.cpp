class Solution {
public:
    int check(vector<int>& nums,int& m,int& k)
    {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            cnt+=(nums[i]-1)/m;
            if(cnt>k) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(),nums.end());
        int l=1;
        int h=nums[nums.size()-1];
        int ans=h;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(check(nums,m,maxOperations))
            {
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};
