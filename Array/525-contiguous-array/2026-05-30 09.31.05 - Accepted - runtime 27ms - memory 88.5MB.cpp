class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n= nums.size();
        unordered_map<int ,int>mp;
        mp[0]=-1;
        int psum=0;
        int ans=0;
        for (auto &x : nums)
            {if (x==0)
                     x=-1;
            }
        for (int i=0;i<n;i++)
            {
                psum+=nums[i];
                int p=psum;
                if(mp.count(p)) ans=max(ans,i-mp[p]);
                if(!mp.count(psum))
                {
                mp[psum]=i;
                }
            }
        return ans;
    }
};