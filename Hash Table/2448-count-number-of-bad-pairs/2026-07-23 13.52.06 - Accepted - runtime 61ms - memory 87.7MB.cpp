class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int >mp;
        long long bp=0;
        for (int i=0;i<nums.size();i++)
            {
                int dif=i-nums[i];
                long long gp=0;
                if(mp.count(dif)!=0)
                    gp=mp[dif];
                bp+=i-gp;
                mp[dif]++;
            }
        return bp; 
    }
};