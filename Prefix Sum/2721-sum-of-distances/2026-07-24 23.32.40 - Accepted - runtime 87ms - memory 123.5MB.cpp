class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>>cnt;
        vector<long long>ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            cnt[nums[i]].push_back(i);
        }
        for(auto it:cnt)
        {
            vector<int >& pos=it.second;
            int m=pos.size();
            vector<long long>ps(m);
            ps[0]=pos[0];
            for(int i=1 ;i< m;i++)
            {
                ps[i]=ps[i-1]+pos[i];
            }
            for(int i=0;i<m;i++)
            {
                long long left=0,right=0;
                  if (i > 0) {
                    left = 1LL * pos[i] * i - ps[i - 1];
                }
                if (i < m - 1) {
                    long long rightSum = ps[m - 1] - ps[i];
                    right = rightSum - 1LL * pos[i] * (m - i - 1);
                }
                ans[pos[i]]=left+right;
            }
        }
        return ans;
    }
};