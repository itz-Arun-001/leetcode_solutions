class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long tots=accumulate(nums.begin(),nums.end(),0LL);
        int rem=tots%p;
        if(rem==0) return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        long long ps=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            ps+=nums[i];
            int currem=ps%p;
            int want=(currem-rem+p)%p;
            if(mp.find(want)!=mp.end())
            {
                ans=min(ans,i-mp[want]);
            }
            mp[currem]=i;
        }
        return (ans==nums.size())?-1:ans;;


    }
};
