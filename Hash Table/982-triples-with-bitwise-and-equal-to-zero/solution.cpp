class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                freq[nums[i]&nums[j]]++;
            }
        }
        int cnt=0;
        for(auto x:freq)
        {
            for(int k=0;k<n;k++)
            {
                if((x.first&nums[k])==0) cnt+=x.second;
            }
        }
        return cnt;
    }
};
